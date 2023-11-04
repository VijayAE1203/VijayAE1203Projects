from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
from CANProcessor import CANProcessor
import os
from Utils import getPaths

class MF4Handler(FileSystemEventHandler):
    def on_created(self, event):
        absoluteFilePath = event.src_path
        if os.path.exists(absoluteFilePath) & os.path.isfile(absoluteFilePath):
            fileExtension = absoluteFilePath.split('.')[-1]
        else:
            fileExtension = "NULL"

        #TODO: Add threading
        if fileExtension=='MF4':
            CANProcessorInstance = CANProcessor(absoluteFilePath)
            print("Started conversion from MF4 to CSV")
            CANProcessorInstance.convertRawMF4toCSV()
            CANProcessorInstance.convertExtractedMF4toCSV()
            print("Converted recent mf4 to csv")
            CANProcessorInstance.checkAlerts()
            del CANProcessorInstance
        else:
            pass

if __name__ == "__main__":
    observer = Observer()
    eventHandler = MF4Handler()
    observer.schedule(eventHandler, path = getPaths('logFolderPath'), recursive = False)
    observer.start()
    try:
        while True:
            pass
    except KeyboardInterrupt:
        observer.stop()
    observer.join()