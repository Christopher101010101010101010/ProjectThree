import re
import string


def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v

def ListAll():
    #output title of section
    print("\nList of All Items Purchased and Number of Purchases \n")

    #open Input_File.txt with f handle and read each line of the document to the InventoryLines list
    f = open("../Release/Input_File.txt")
    InventoryLines = f.read().splitlines()
    #print(InventoryLines)
   
   #for int i in range 0 to length of InventoryLines list
    for i in range(0, len(InventoryLines)):
        #define counter to integer 0 and testVar to the first string in InventoryLines list
        counter = 0
        testVar = InventoryLines[i]
        #for int j in range of 0 to length of InventoryLines list
        for j in range(0, len(InventoryLines)):
            #if index j of InventoryLines is equivalent to testVar increment counter
            if InventoryLines[j] == testVar:
                counter = counter + 1

        #output testVar " purchased " counter " times"
        print(testVar, " purchased ", counter, " times")

        #for j in 0 to counter
        for j in range(0, counter):
            #remove all occurances of testVar in InventoryLines list
            InventoryLines.remove(testVar)

    #close f handle
    f.close()

def ItemFrequency():
    #open Input_File.txt and assign to f handle and read each line of the .txt document to InventoryLines list
    f = open("../Release/Input_File.txt")
    InventoryLines = f.read().splitlines()

    #output section title
    print("\nSpecific Item Purchase Frequency\n")
  
    #obtain user input and output "Enter item: " prompt
    itemPurchased = input("Enter item: ")
   
    #initialize counter to 0
    counter = 0
    
    #for i in range of 0 to length of InventoryLines list
    for i in range(0, len(InventoryLines)):
        #if itemPurchased is equivalent to InventoryLines element at index i
        if InventoryLines[i] == itemPurchased:
            #increment counter
            counter = counter + 1
    #output itemPurchased " purchased " counter " times"
    print(itemPurchased, "was purchased ", counter, " times")

    #close f handle
    f.close()
    itemPurchased = ""

    
def HistogramList():
    #output section title
    print("\nText-Based Histogram Listing All Items Purchased")

    #open Input_File.txt to f handle and read each line of the file to InventoryLines list 
    f = open("../Release/Input_File.txt")
    InventoryLines = f.read().splitlines()
   
    #for i in range of 0 to length of InventoryLines list
    for i in range(0, len(InventoryLines)):
        #declare symbolStr as a string and testVar to the i index of InventoryLines list 
        symbolStr = ""
        counter = 0
        testVar = InventoryLines[i]
        #for j in range of 0 to length of InventoryLines list
        for j in range(0, len(InventoryLines)):
            #if j index of InventoryLines list is equivelent to testVar
            if InventoryLines[j] == testVar:
                #append "*" to symbolStr and increment counter
                symbolStr += "*"
                counter = counter + 1
        #output testVar " " symbolStr
        print(testVar, " ", symbolStr)

        #for j in range 0 to counter
        for j in range(0, counter):
            #remove testVar from InventoryLines list
            InventoryLines.remove(testVar)
    
    #close f handle
    f.close()