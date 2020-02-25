# High-Performance-Computing-
This repository contains lab work of High Performance Computing. This course is offered at DA-IICT in 6th semester (3rd Year). The main purpose of this course is to get maximum throughput from any system. Depending upon the cache size, processor and using multi threading via open-mp, we are analyzing the performance, its efficiency, speedup, throughput of any given code. How to parallelized any given serial code and how to use spatial or temporal locality in order to achieve best computing performance is the goal for this course. 

Other than this, all the required files, codes, results, reports, are available in the folder. 
Remember, we use bash script to run this all codes which will automatically generate the result in CSV file for us. We uploaded this csv file to http://letshpc.herokuapp.com/customdata website, then simply plot the result and analyzed it.  

# Procedure
To run the bash script successfully, place your code_file with the name given in the maps.py file and place it in all_codes folder.
1) The name of the code file must be in the particular order like, "parallel_measurement" and "serial_measurement". 
2) These two file must be placed in one folder which will have name "201701073_201701074_[problem_list]_[approaches]". 
   Approaches and problem_list can be found from maps.py. 
3) The folder which you have made should be placed in a folder called all_codes. 
4) Finally run the script called "run_script_without_perf.sh". 
5) The result will be generated in CSV file which can be uploaded on the website given above.

Note : your logic should be lies within the */write your code here*/ in the "parallel_measurement" and "serial_measurement" file.Though sample file is uploaded here which you can easily refer. 
