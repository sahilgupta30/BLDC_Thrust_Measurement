import serial
import csv

ser = serial.Serial(port="COM34", baudrate= 115200, timeout=2)

# Input: File path and the string to add as a row
file_path = "file.csv"
while True:
    input_string = ser.readline()

    # Split the input string by a delimiter (e.g., comma) to create a list of values
    data = input_string.split(',')

    # Open the CSV file in append mode and write the data as a new row
    with open(file_path, 'a', newline='') as csvfile:
        csv_writer = csv.writer(csvfile)
        csv_writer.writerow(data)

    