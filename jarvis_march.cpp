#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

using namespace std;
typedef vector<pair<double, double>> vpdd;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pair<int, double>> vpid;
typedef pair<int, double> pid;
vpdd hull_jmarch;

bool ccw(pdd a, pdd b, pdd c);
void jarvis_march(const vpdd &input);


double time_elapsed(struct timespec *start, struct timespec *end)
{
    double t;
    t = (end->tv_sec - start->tv_sec);                  // diff in seconds
    t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
    return t;
}

int main()
{
   struct timespec start;
    struct timespec end;

    for (int a1 = 1; a1 <= 16; a1++)
    {
        
        string inp1, op1, op2;
        inp1 = "inputs_100/input"+to_string(a1)+".txt";
        op1 = "outputs_100/output_jm_convexhull"+to_string(a1)+".txt";
        // op2 = "outputs/jarvis_march/output" + to_string(a1) + ".txt";
        ifstream file1(inp1);
        ofstream file2(op1);
        file2 << std::setprecision(9) << std::showpoint << std::fixed;
        // ofstream file3(op2);
        stringstream ss;

        int t;
        file1 >> t;

        // cout << "T is " << t << "\n";
        vpdd input;
        string temp;
        double temp1;
        double temp2;

        string temp3, temp4;
        getline(file1, temp);
        
        for (int i = 0; i < t; i++)
        {
            getline(file1, temp);

            // cout << temp;
            ss << temp;
            while (!ss.eof())
            {
                getline(ss, temp3, ',');
                getline(ss, temp4, '\n');
                temp1 = stod(temp3);
                temp2 = stod(temp4);
            }
            ss.clear();
            // cout<<"Temps are "<<temp1<<" "<<temp2<<"\n";
            input.push_back(make_pair(temp1, temp2));
            
        }

      
        hull_jmarch.clear();

        clock_gettime(CLOCK_REALTIME, &start);
        jarvis_march(input);
        clock_gettime(CLOCK_REALTIME, &end);

        // file2 << "Hull is\n\n";
        // sort(hull_quick.begin(),hull_quick.end());
        file2 << hull_jmarch.size() << "\n";
        for (auto &i : hull_jmarch)
        {
            file2 << i.first << ", " << i.second << "\n";
        }


        file2 << std::setprecision(9) << std::showpoint << std::fixed;
        file2 << time_elapsed(&start, &end);

        

        
    }



    for (int a1 = 1; a1 <= 16; a1++)
    {
        string inp1, op1, op2;
        inp1 = "inputs_1000/input"+to_string(a1)+".txt";
        op1 = "outputs_1000/output_jm_convexhull"+to_string(a1)+".txt";
        // op2 = "outputs/jarvis_march/output" + to_string(a1) + ".txt";
        ifstream file1(inp1);
        ofstream file2(op1);
        file2 << std::setprecision(9) << std::showpoint << std::fixed;
        // ofstream file3(op2);
        stringstream ss;

        int t;
        file1 >> t;

        // cout << "T is " << t << "\n";
        vpdd input;
        string temp;
        double temp1;
        double temp2;

        string temp3, temp4;
        getline(file1, temp);
        
        for (int i = 0; i < t; i++)
        {
            getline(file1, temp);

            // cout << temp;
            ss << temp;
            while (!ss.eof())
            {
                getline(ss, temp3, ',');
                getline(ss, temp4, '\n');
                temp1 = stod(temp3);
                temp2 = stod(temp4);
            }
            ss.clear();
            // cout<<"Temps are "<<temp1<<" "<<temp2<<"\n";
            input.push_back(make_pair(temp1, temp2));
            
        }

      
        hull_jmarch.clear();

        clock_gettime(CLOCK_REALTIME, &start);
        jarvis_march(input);
        clock_gettime(CLOCK_REALTIME, &end);

        // file2 << "Hull is\n\n";

        // sort(hull_quick.begin(),hull_quick.end());

        file2 << hull_jmarch.size() << "\n";
        for (auto &i : hull_jmarch)
        {
            file2 << i.first << ", " << i.second << "\n";
        }

        file2 << std::setprecision(9) << std::showpoint << std::fixed;
        file2 << time_elapsed(&start, &end);

        

        
    }



    for (int a1 = 1; a1 <= 16; a1++)
    {
        string inp1, op1, op2;
        inp1 = "inputs_10000/input"+to_string(a1)+".txt";
        op1 = "outputs_10000/output_jm_convexhull"+to_string(a1)+".txt";
        // op2 = "outputs/jarvis_march/output" + to_string(a1) + ".txt";
        ifstream file1(inp1);
        ofstream file2(op1);
        file2 << std::setprecision(9) << std::showpoint << std::fixed;
        // ofstream file3(op2);
        stringstream ss;

        int t;
        file1 >> t;

        // cout << "T is " << t << "\n";
        vpdd input;
        string temp;
        double temp1;
        double temp2;

        string temp3, temp4;
        getline(file1, temp);
        
        for (int i = 0; i < t; i++)
        {
            getline(file1, temp);

            // cout << temp;
            ss << temp;
            while (!ss.eof())
            {
                getline(ss, temp3, ',');
                getline(ss, temp4, '\n');
                temp1 = stod(temp3);
                temp2 = stod(temp4);
            }
            ss.clear();
            // cout<<"Temps are "<<temp1<<" "<<temp2<<"\n";
            input.push_back(make_pair(temp1, temp2));
            
        }

      
        hull_jmarch.clear();

        clock_gettime(CLOCK_REALTIME, &start);
        jarvis_march(input);
        clock_gettime(CLOCK_REALTIME, &end);

        // file2 << "Hull is\n\n";
        // sort(hull_quick.begin(),hull_quick.end());
        file2 << hull_jmarch.size() << "\n";
        for (auto &i : hull_jmarch)
        {
            file2 << i.first << ", " << i.second << "\n";
        }

        file2 << std::setprecision(9) << std::showpoint << std::fixed;
        file2 << time_elapsed(&start, &end);

        

        
    }
    return 0;
}

bool ccw(pdd a, pdd b, pdd c)
{
    return ((c.first - a.first) * (b.second - a.second) - (c.second - a.second) * (b.first - a.first)) < 0;
}
void jarvis_march(const vpdd &input)
{

    int n = input.size();
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i].first < input[left].first)
        {
            left = i;
        }
    }

    int first_point = left;
    int third_point;
    do
    {
        hull_jmarch.push_back(input[first_point]);
        // cout<<"here\n";
        third_point = (first_point + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (ccw(input[first_point], input[i], input[third_point]))
            {
                third_point = i;
            }
        }

        first_point = third_point;

    } while (first_point != left);
}