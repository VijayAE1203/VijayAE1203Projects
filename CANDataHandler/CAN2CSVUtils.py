from asammdf import MDF
from pathlib import Path
import os
from Utils import makeDir

#Export mf4 to csv with or without extraction
def MF4toCSVConverter(MF4FilePath, folderOut, dbcFilePath = '', extract=False):
    currPath = os.getcwd()
    MF4FileName = MF4FilePath.split('\\')[-1]
    MF4FolderPath = MF4FilePath.split(MF4FileName)[0]
    os.chdir(MF4FolderPath)
    mdf = MDF(MF4FileName)
    fileOut = MF4FileName.replace(".MF4",".csv")
    makeDir(folderOut)
    childFolderOut = folderOut+'\\'+MF4FileName.split('.')[0]
    makeDir(childFolderOut)

    if(extract):
        dbcFile = {"CAN": [(dbcFilePath,0)]}
        mdfExtracted = mdf.extract_bus_logging(dbcFile)
        mdfExtracted.export(fmt='csv', filename= Path(childFolderOut, fileOut))
    else:
        mdf.export(fmt='csv', filename= Path(childFolderOut, fileOut))

    os.chdir(currPath)

    return childFolderOut