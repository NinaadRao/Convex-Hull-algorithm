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

vpdd hull_quick;


void quickhull(const vpdd &input);
int getsign(pdd a, pdd b, pdd c);
void qhullrecur(const vpdd &input, pdd a, pdd b);
double dist(pdd a, pdd b, pdd c);
bool get_right(pdd a, pdd b, pdd c);


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
        op1 = "outputs_100/output_qh_convexhull"+to_string(a1)+".txt";
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

      
        hull_quick.clear();

        clock_gettime(CLOCK_REALTIME, &start);
        quickhull(input);
        clock_gettime(CLOCK_REALTIME, &end);

        // file2 << "Hull is\n\n";
        // sort(hull_quick.begin(),hull_quick.end());
        file2 << hull_quick.size() << "\n";
        for (auto &i : hull_quick)
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
        op1 = "outputs_1000/output_qh_convexhull"+to_string(a1)+".txt";
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

      
        hull_quick.clear();

        clock_gettime(CLOCK_REALTIME, &start);
        quickhull(input);
        clock_gettime(CLOCK_REALTIME, &end);

        // file2 << "Hull is\n\n";

        // sort(hull_quick.begin(),hull_quick.end());

        file2 << hull_quick.size() << "\n";
        for (auto &i : hull_quick)
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
        op1 = "outputs_10000/output_qh_convexhull"+to_string(a1)+".txt";
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

      
        hull_quick.clear();

        clock_gettime(CLOCK_REALTIME, &start);
        quickhull(input);
        clock_gettime(CLOCK_REALTIME, &end);

        // file2 << "Hull is\n\n";
        // sort(hull_quick.begin(),hull_quick.end());
        file2 << hull_quick.size() << "\n";
        for (auto &i : hull_quick)
        {
            file2 << i.first << ", " << i.second << "\n";
        }

        file2 << std::setprecision(9) << std::showpoint << std::fixed;
        file2 << time_elapsed(&start, &end);

        

        
    }
    return 0;
}

void quickhull(const vpdd &input)
{

    int min_x = 0, max_x = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i].first < input[min_x].first)
        {
            min_x = i;
        }
        if (input[i].first > input[max_x].first)
        {
            max_x = i;
        }
    }

    hull_quick.push_back(input[min_x]);
    hull_quick.push_back(input[max_x]);

    vpdd left, right;
    for (int i = 0, temp; i < input.size(); i++)
    {
        if (i == min_x || i == max_x)
        {
            continue;
        }
        temp = getsign(input[min_x], input[max_x], input[i]);
        if (temp == 0)
        {
            continue;
        }
        if (temp < 0)
        {
            left.push_back(input[i]);
        }
        else
        {
            right.push_back(input[i]);
        }
    }
    qhullrecur(right, input[min_x], input[max_x]);
    qhullrecur(left, input[max_x], input[min_x]);
}

void qhullrecur(const vpdd &input, pdd a, pdd b)
{

    if (input.size() == 0)
    {
        return;
    }
    vpdd right_p;
    pid max_ind = make_pair(-1, 0);

    for (int i = 0; i < input.size(); i++)
    {
        if (get_right(a, b, input[i]))
        {
            if (max_ind.second < dist(a, b, input[i]))
            {
                max_ind.first = i;
                max_ind.second = dist(a, b, input[i]);
            }
        }
    }

    pdd c = input[max_ind.first];
    hull_quick.push_back(c);

    vpdd acr, bcr;
    for (int i = 0; i < input.size(); i++)
    {
        if (get_right(a, c, input[i]))
        {
            acr.push_back(input[i]);
        }
        if (get_right(c, b, input[i]))
        {
            bcr.push_back(input[i]);
        }
    }
    qhullrecur(acr, a, c);
    qhullrecur(bcr, c, b);
}
int getsign(pdd a, pdd b, pdd c)
{
    int d = (c.first - a.first) * (b.second - a.second) - (c.second - a.second) * (b.first - a.first);
    return d;
}

bool get_right(pdd a, pdd b, pdd c)
{
    return ((c.first - a.first) * (b.second - a.second) - (c.second - a.second) * (b.first - a.first)) > 0;
}

double dist(pdd a, pdd b, pdd c)
{
    return abs((c.first - a.first) * (b.second - a.second) - (c.second - a.second) * (b.first - a.first));
}
