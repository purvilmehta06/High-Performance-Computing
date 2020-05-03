# High-Performance-Computing-
This repository contains lab work of High Performance Computing and project files. This course is offered at DA-IICT in 6th semester (3rd Year). The main purpose of this course is to get maximum throughput from any system. Depending upon the cache size, processor and using multi threading via open-mp, we are analyzing the performance, its efficiency, speedup, throughput of any given code. How to parallelized any given serial code and how to use spatial or temporal locality in order to achieve best computing performance is the goal for this course. 

Other than this, all the required files, codes, results, reports, are available in the folder. 
Remember, we use python script to run this all codes which will automatically generate the result in txt file for us. We uploaded this txt file to http://letshpc.herokuapp.com/customdata website, then simply plot the result and analyzed it.  

# Procedure
To run the python script successfully, place your two codes file under the name "parallel.c" and "serial.c" in Script folder. As of now there are three files in the Script folder.
1) config.py : This file contains the problem size and thread details. By default problem size is set to 2<sup>4</sup> to 2<sup>12</sup> and processors are set to 4,8,12 and 16. processors 0 means the serial code execution.
2) main.py: This file contains the main script. Before you do `python main.py` on terminal, remember to place two code files paralle.c and serial.c in this folder.
<<<<<<< HEAD
3) merge.py: This file takes different txt files and merge them into 1 file. When you have two output txt files for the same code where one file contsins x runs data and second file contains y runs data, merge.py takes both files and merge them making x+y runs data in a single file. To use this file make one folder called fragments and place all output txt file in the folder which you want to merge. 
