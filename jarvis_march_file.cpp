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

   
        
        string inp1, op1, op2;
        // inp1 = "inputs_100/input"+to_string(a1)+".txt";
        // op1 = "outputs_100/output_qh_convexhull"+to_string(a1)+".txt";
        // op2 = "outputs/jarvis_march/output" + to_string(a1) + ".txt";
        // ifstream file1(inp1);
        // ofstream file2(op1);
        cout << std::setprecision(9) << std::showpoint << std::fixed;
        // ofstream file3(op2);
        stringstream ss;

        int t;
        cin >> t;
        // cout<<"T is "<<t<<"\n";
        // cout << "T is " << t << "\n";
        vpdd input;
        string temp;
        double temp1;
        double temp2;

        string temp3, temp4;
        // getline(file1, temp);
        
        for (int i = 0; i < t; i++)
        {
            cin>>temp;
            temp.pop_back();
            // temp =stod(temp);
            temp1 = stod(temp);
            cin>>temp;
            temp2=stod(temp);
            // cout<<"temp is "<<temp<<"\n";
            // cout << temp;
                // cout<<"Temps are "<<temp1<<" "<<temp2<<"\n";
            input.push_back(make_pair(temp1, temp2));
            
        }

        sort(input.begin(),input.end());
        hull_jmarch.clear();

        clock_gettime(CLOCK_REALTIME, &start);
        jarvis_march(input);
        clock_gettime(CLOCK_REALTIME, &end);

        // file2 << "Hull is\n\n";
        // sort(hull_quick.begin(),hull_quick.end());
        cout << hull_jmarch.size() << "\n";
        for (auto &i : hull_jmarch)
        {
            cout << i.first << ", " << i.second << "\n";
        }


        cout << std::setprecision(9) << std::showpoint << std::fixed;
        cout << time_elapsed(&start, &end);

    return 0;
}

bool ccw(pdd a, pdd b, pdd c)
{
    return ((c.first - a.first) * (b.second - a.second) - (c.second - a.second) * (b.first - a.first)) < 0;
}
vpdd jarvis_march(const vpdd &input)
{

    int n = input.size();
    vpdd hull_jmarch;
    if(n<3){
        hull_jmarch.push_back(make_pair(-1,-1))
    
        return hull_jmarch;
    }
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
    return hull_jmarch;
}