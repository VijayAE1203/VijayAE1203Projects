This folder has the contents of the project 'CANDataHandler'

# Purpose:
* This project aims at automatically decoding CAN log files from vehicles in *.mf4 format using a CAN database file and storing the physical values in a timeseries format in *.csv format. During this process, it also monitors the channels for any outliers and stores the outliers separately. Some of these settings are configurable to match individual needs.
* The current does the following tasks
    * Monitors the 'CANData' folder for any new MF4 files
    * Uses a CAN dbc file to convert the MF4 files to raw physical values and store them in separate spreadsheets
    * Checks if the physical values are within a certain limit (specified in config.yaml file)
    * Extracts the datapoints if they are outside the limits and stores them in separate spreadsheets

# How to run it:
* Install [python](https://www.python.org/downloads/) and [pip](https://pip.pypa.io/en/stable/installation/)
* Clone the repository
* Open a terminal and navigate to the CANDataHandler path in your computer
* Execute the following command to get the python packages listed in 'requirements.txt'
    * pip install -r requirements.txt
* Open the 'config.yaml' file in a text editor and replace the folder paths with your corresponding local paths
* Navigate to the scripts folder in the terminal and run the following command to start the python program
    * python .\FileWatcher.py
* Open up your file explorer and navigate to the CANData folder. Cut and paste the .MF4 file somewhere else and move it back into the CANData
  folder. This will trigger the FileWatcher and in turn trigger all the tasks that are mentioned above. You should see new folders created for
  raw CAN data, decoded CAN data and alerts (contains datapoints that exceed the limits specified in the config.yaml)
