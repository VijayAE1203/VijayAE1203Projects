from CAN2CSVUtils import MF4toCSVConverter
from Utils import getPaths, parseAlerts, getSamplingFrequency
import glob
import pandas as pd
import matplotlib.pyplot as plt
from spicy import signal

class CANProcessor():
    def __init__(self, MF4FilePath):
        self.MF4FilePath = MF4FilePath
        self.rawDataCSVPath = getPaths('rawDataCSVPath')
        self.extractedDataCSVPath = getPaths('extractedDataCSVPath')
        self.dbcFilePath = getPaths('dbcFilePath')
        self.convertExtractedMF4toCSV()

    def convertRawMF4toCSV(self):
        self.rawCSVFileFolder = MF4toCSVConverter(self.MF4FilePath, self.rawDataCSVPath, False)
        return self.rawCSVFileFolder
     
    def convertExtractedMF4toCSV(self):
        self.extractedCSVFileFolder = MF4toCSVConverter(self.MF4FilePath, self.extractedDataCSVPath, self.dbcFilePath, True)
        return self.extractedCSVFileFolder
    
    def getData(self, signalName):
        extractedCSVFiles = glob.glob(self.extractedCSVFileFolder + "/*.csv")
        for file in extractedCSVFiles:
            df = pd.read_csv(file)
            for col in df.columns:
                if signalName in col:
                    signalData = list(df[col])
                    signalTimestamp = list(df['timestamps'])            
                    return signalData, signalTimestamp, file

    def checkAlerts(self):
        self.alerts = parseAlerts()
        for alert in self.alerts:
            filteredSignalData, signalTimestamp = self.filterData(alert)
            alert['On'] = False
            criticalPoints = {'timestamp': [], 'value': []}
            idx = 0
            for dataPoint in filteredSignalData:
                if dataPoint>alert['max'] or dataPoint<alert['min']:
                    alert['On'] = True
                    criticalPoints['timestamp'].append(signalTimestamp[idx])
                    criticalPoints['value'].append(dataPoint)
                idx+=1
            alert['criticalPoints'] = criticalPoints
            print(alert)
    
    def filterData(self, alert):
        signalData, signalTimestamp, file = self.getData(alert['name'])
        alert['filePath'] = file
        fs = getSamplingFrequency(signalTimestamp)
        fc = alert['cutOff']
        filterOrder = alert['filterOrder']
        w = fc/(fs/2)
        b,a = signal.butter(filterOrder, w, 'low')
        filteredSignalData = signal.filtfilt(b,a,signalData)
        return list(filteredSignalData), signalTimestamp
    
    def exportCriticalData():
        pass
            