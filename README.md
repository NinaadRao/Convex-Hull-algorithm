# Convex-Hull-algorithm
Four algorithms to implement the problem of finding the smallest convex polygon for a set of points which contains all the points in the plane.
The four algorithms are:
1. The divide and conquer approach
2. The Graham Scan Algorithm.
3. Jarvis March Algorithm.
4. Quickhull Algorithm.

There are two options for executing the code.
One is where the user gives the input and for this set of points, the convex polygon is found for these points using the divide and conquer approach.

The second approach is running for the predefined inputs which vary from input size 10 to 1000000. the range of the inputs 
changes from (0,100), (0,1000) and (0,10000). This will run for 48 different test cases and will take time to plot all the graphs since the size of inputs increases to 1000000.<br/>
The user interface is written in python and the algorithms are written in cpp.<br/>
The implementation files that are called are:
1. divide_and_conquer.cpp(To illustrate the output when the user gives the input).
2. divide_and_conquer_analysis.cpp
3. quickhull.cpp
4. graham_scan.cpp
5. jarvis_march.cpp


Make sure g++ is installed in your system.<br/>
Python modules required: subprocess, matplotlib<br/>
To run the code, run:
python ui.py

Then choose the option you want.

Github link: https://github.com/NinaadRao/Convex-Hull-algorithm
