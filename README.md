# High-Performance-Computing-
This repository contains lab work of High Performance Computing. This course is offered at DA-IICT in 6th semester (3rd Year). The main purpose of this course is to get maximum throughput from any system. Depending upon the cache size, processor and using multi threading via open-mp, we are analyzing the performance, its efficiency, speedup, throughput of any given code. How to parallelized any given serial code and how to use spatial or temporal locality in order to achieve best computing performance is the goal for this course. 

Other than this, all the required files, codes, results, reports, are available in the folder. 
Remember, we use bash script to run this all codes which will automatically generate the result in CSV file for us. We uploaded this csv file to http://letshpc.herokuapp.com/customdata website, then simply plot the result and analyzed it.  

# Procedure
To run the bash script successfully, place your code_file with the name given in the maps.py file and place it in all_codes folder.
1) The name of the code file must be in the particular order like, "parallel_measurement" and "serial_measurement". 
2) These two file must be placed in one folder which will have name "201701073-201701074-[problem_list]_[approaches]". 
   Approaches and problem_list can be found from maps.py. 
3) The folder which you have made should be placed in a folder called all_codes. 
4) Finally run the script called "run_script_without_perf.sh". 
5) The result will be generated in CSV file which can be uploaded on the website given above.

Note : your logic should be lies within the */write your code here*/ in the "parallel_measurement" and "serial_measurement" file.Though sample file is uploaded here which you can easily refer. 

For Example, lets assume we want to run "trapezoidal_critical.c" from the Lab_2 then we have to follow the below steps.
1) Open maps.py and find the problem_list and approaches that we want. In this case it will be trapezoidal and critical.
2) Change the name of the file from "trapezoidal_critical.c" to "parallel_measurement.c" and create serial file for the same code by    yourself (without openmp tag and parallelization) as "serial_measurement.c".
3) Place this two file under a folder called "201701073-201701074-[probelm_list]_[approaches]".
4) Place this folder in all_codes folder.
5) Run "run_script_without_perf.sh" from terminal. This will create one CSV file in the same folder.

Note: All reqruired files must be in same folder called Script.

# Hierarchy
<pre>
Script  
   all_codes  
      201701073-201701074-trapezoidal_critical  
         serial_measurement.c  
         parallel_measurement.c  
   collect_data_without_perf.py  
   main_script_without_perf.py  
   maps.py  
   README.md  
   run_script_without_perf.sh  
   txt_to_csv.py  
   llncs.clc  
</pre>
