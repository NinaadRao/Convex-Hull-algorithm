#include <iostream> 
#include <stack> 
#include <stdlib.h> 
#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <sstream>
#include <string.h>
#include <unistd.h>
#include <iomanip>


using namespace std; 

typedef vector<pair<double, double>> vpdd;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pair<int, double>> vpid;
typedef pair<int, double> pid;
vpdd hull;

double time_elapse(struct timespec * start,struct timespec * end){
	double t;
	t=end->tv_sec-start->tv_sec;
	t+=(end->tv_nsec-start->tv_nsec)*0.000000001;
	return t;	
}

struct Point 
{ 
	double x; 
	double y; 
}; 

Point p0; 

Point nextToTop(stack<Point> &S) 
{ 
	Point p = (S).top(); 
	S.pop(); 
	Point res = S.top(); 
	S.push(p); 
	return res; 
} 

void swap(Point &p1, Point &p2) 
{ 
	Point temp = p1; 
	p1 = p2; 
	p2 = temp; 
} 

double distSq(Point p1, Point p2) 
{ 
	return (p1.x - p2.x)*(p1.x - p2.x) + 
		(p1.y - p2.y)*(p1.y - p2.y); 
} 

long long int orientation(Point p, Point q, Point r) 
{ 
	double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
	if (val == 0) return 0; 
	return (val > 0)? 1: 2; 
} 

int compare(const void *vp1, const void *vp2) 
{ 
Point *p1 = (Point *)vp1; 
Point *p2 = (Point *)vp2; 

long long int o = orientation(p0, *p1, *p2); 
if (o == 0) 
	return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 

return (o == 2)? -1: 1; 
} 


vpdd convexHull(Point points[], long long int n) 
{ 
	long long int ymin = points[0].y, min = 0; 
	for (long long int i = 1; i < n; i++) 
	{ 
		long long int y = points[i].y; 

		if ((y < ymin) || (ymin == y && 
			points[i].x < points[min].x)) 
			ymin = points[i].y, min = i; 
	} 

	swap(points[0], points[min]); 

	p0 = points[0]; 
	qsort(&points[1], n-1, sizeof(Point), compare); 
	vpdd output;
	
	long long int m = 1; 
	for (long long int i=1; i<n; i++) 
	{ 
		while (i < n-1 && orientation(p0, points[i], 
										points[i+1]) == 0) 
			i++; 


		points[m] = points[i]; 
		m++;
	} 
	if (m < 3){ return output;
	} 
	stack<Point> S; 
	S.push(points[0]); 
	S.push(points[1]); 
	S.push(points[2]); 

	for (int i = 3; i < m; i++) 
	{ 
		while (orientation(nextToTop(S), S.top(), points[i]) != 2) 
			S.pop(); 
		S.push(points[i]); 
	} 
	// Now stack has the output points, print contents of stack 
	
	//int i=0;
	long long int len=S.size();
	pair <double,double> Pair1 ; 
	while (!S.empty()) 
	{ 
		Point p = S.top();
		Pair1.first=p.x;
		Pair1.second=p.y; 
		//cout << p.x << ", " << p.y << endl;
		output.push_back(Pair1) ;
		S.pop(); 
	} 
	//sort(output.begin(),output.end());
	/*for(int i=0;i<len;i++){
		cout << output[i].first << ", " << output[i].second << endl;
		
	}*/
	return output;  

} 



int main(){
	struct timespec start,end;
	long long int N;
	for(int j=1;j<=16;j++){

//	cin >> N;
	//scanf("%lld",&N);
	//cout << N << endl;
//	printf("%lld\n",N );
	string inp1,op1;
        inp1 = "inputs_100/input"+to_string(j)+".txt";
        op1 = "outputs_100/output_gs_convexhull"+to_string(j)+".txt";
        ifstream file1(inp1);
        ofstream file2(op1);
        stringstream ss;

        file2 << std::setprecision(9) << std::showpoint << std::fixed;

        int t;
        file1 >> t;

        //cout << "T is " << t << "\n";
        vpdd input;
        string temp;
        double temp1;
        double temp2;

        string temp3, temp4;
        getline(file1, temp);
        Point *input1 = new Point[t];
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
            input1[i].x = temp1;
            input1[i].y = temp2;
        }

    
	clock_gettime(CLOCK_REALTIME,&start);
	vpdd output=convexHull(input1,t);
	clock_gettime(CLOCK_REALTIME,&end);

    // sort(output.begin(),output.end());
	file2 << output.size() << "\n";
        for (auto &i : output)
        {
            file2 << i.first << ", " << i.second << "\n";
        }
        double time=time_elapse(&start,&end);
        file2 << time;
	}

	for(int j=1;j<=16;j++){

//	cin >> N;
	//scanf("%lld",&N);
	//cout << N << endl;
//	printf("%lld\n",N );
	string inp1,op1;
        inp1 = "inputs_1000/input"+to_string(j)+".txt";
        op1 = "outputs_1000/output_gs_convexhull"+to_string(j)+".txt";
        ifstream file1(inp1);
        ofstream file2(op1);
        stringstream ss;
        file2 << std::setprecision(9) << std::showpoint << std::fixed;

        int t;
        file1 >> t;

        //cout << "T is " << t << "\n";
        vpdd input;
        string temp;
        double temp1;
        double temp2;

        string temp3, temp4;
        getline(file1, temp);
        Point *input1 = new Point[t];
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
            input1[i].x = temp1;
            input1[i].y = temp2;
        }

    
	clock_gettime(CLOCK_REALTIME,&start);
	vpdd output=convexHull(input1,t);
	clock_gettime(CLOCK_REALTIME,&end);

    // sort(output.begin(),output.end());

	file2 << output.size() << "\n";
        for (auto &i : output)
        {
            file2 << i.first << ", " << i.second << "\n";
        }
        double time=time_elapse(&start,&end);
        file2 << time;
	}
	for(int j=1;j<=16;j++){

//	cin >> N;
	//scanf("%lld",&N);
	//cout << N << endl;
//	printf("%lld\n",N );
	string inp1,op1;
        inp1 = "inputs_10000/input"+to_string(j)+".txt";
        op1 = "outputs_10000/output_gs_convexhull"+to_string(j)+".txt";
        ifstream file1(inp1);
        ofstream file2(op1);
        file2 << std::setprecision(9) << std::showpoint << std::fixed;
        stringstream ss;

        int t;
        file1 >> t;

        //cout << "T is " << t << "\n";
        vpdd input;
        string temp;
        double temp1;
        double temp2;

        string temp3, temp4;
        getline(file1, temp);
        Point *input1 = new Point[t];
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
            input1[i].x = temp1;
            input1[i].y = temp2;
        }

    
	clock_gettime(CLOCK_REALTIME,&start);
	vpdd output=convexHull(input1,t);
	clock_gettime(CLOCK_REALTIME,&end);
    // sort(output.begin(),output.end());
	file2 << output.size() << "\n";
        for (auto &i : output)
        {
            file2 << i.first << ", " << i.second << "\n";
        }
        double time=time_elapse(&start,&end);
        // file2 << std::setprecision(9) << std::showpoint << std::fixed;
        file2 << time;
	}
	return 0;
}
