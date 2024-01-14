import os
import yaml
from statistics import mean

def makeDir(dirPath):
    if os.path.exists(dirPath):
        pass
    else:
        os.mkdir(dirPath)

def parseYaml():
    with open('config.yml','r') as yamlFile:
        yamlContent = yaml.safe_load(yamlFile)
    yamlFile.close()
    return yamlContent

def getPaths(File):
    yamlContent = parseYaml()
    return yamlContent[File]

def parseAlerts():
    yamlContent = parseYaml()
    alerts = yamlContent['alerts']
    signals = list(alerts.keys())
    parsedAlerts = []
    for signal in signals:
        signalattr = alerts[signal]
        signalattr['name'] = signal
        parsedAlerts.append(signalattr)
    return parsedAlerts

def getSamplingFrequency(timeStamps):
    idx = 0
    deltaT = []
    while idx<len(timeStamps)-1:
        deltaT.append(timeStamps[idx+1]-timeStamps[idx])
        idx+=1
    ts = round(mean(deltaT),2)
    fs = 1/ts
    return fs
