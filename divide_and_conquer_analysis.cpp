#include<iostream>
#include<bits/stdc++.h> 
#include<time.h>
using namespace std; 
#include<algorithm>
// stores the centre of polygon (It is made 
// global because it is used in compare function) 

typedef vector<pair<double, double>> vpdd;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pair<int, double>> vpid;
typedef pair<int, double> pid;

pair<double, double> mid; 



bool ccw(pdd a, pdd b, pdd c);
vpdd jarvis_march(const vpdd &input);



double time_elapsed(struct timespec * start,struct timespec * end){
    double t;
    t=end->tv_sec-start->tv_sec;
    t+=(end->tv_nsec-start->tv_nsec)*0.000000001;
    return t;   
}


// determines the quadrant of a point 
// (used in compare()) 
int quad(pair<double, double> p) 
{ 
    if (p.first >= 0 && p.second >= 0) 
        return 1; 
    if (p.first <= 0 && p.second >= 0) 
        return 2; 
    if (p.first <= 0 && p.second <= 0) 
        return 3; 
    return 4; 
} 

// Checks whether the line is crossing the polygon 
int orientation(pair<double,double> a, pair<double,double> b, 
                pair<double,double> c) 
{ 
    //printf("enterd\n");
    double res = (b.second-a.second)*(c.first-b.first) - 
            (c.second-b.second)*(b.first-a.first); 
    //printf("this one\n");
    if (res == 0) 
        return 0; 
    if (res > 0) 
        return 1; 
    return -1; 
} 

// compare function for sorting 
bool compare(pair<double,double> p1, pair<double,double> q1) 
{ 
    pair<double , double> p = make_pair(p1.first - mid.first, 
                                p1.second - mid.second); 
    pair<double , double> q = make_pair(q1.first - mid.first, 
                                q1.second - mid.second); 

    int one = quad(p); 
    int two = quad(q); 

    if (one != two) 
        return (one < two); 
    return (p.second*q.first < q.second*p.first); 
} 

// Finds upper tangent of two polygons 'a' and 'b' 
// represented as two vectors. 
vector<pair<double,double>> merger(vector<pair<double,double> > a, 
                            vector<pair<double,double> > b) 
{ 
    // n1 -> number of points in polygon a 
    // n2 -> number of points in polygon b 
    long long int n1 = a.size();
    long long int n2 = b.size();

    
    //printf("line 78\n");
    long long int ia = 0;
    long long int ib = 0; 
    for (long long int i=1; i<n1; i++) 
        if (a[i].first > a[ia].first) 
            ia = i; 
    //  printf("line 84\n");
    // ib -> leftmost point of b 
    for (long long int i=1; i<n2; i++) 
        if (b[i].first < b[ib].first) 
            ib=i; 
    //printf("line 89\n");
    // finding the upper tangent 
    long long int inda = ia;
    long long int indb = ib; 
    //printf("line 94\n");
    bool done = 0; 
    // if(n1==0 || n2==0){
    //     done=1;
    // }
    while (!done) 
    { 
        done = 1;
    //  printf("entered %lld %lld\n",n1,n2); 
        while (orientation(b[indb], a[inda], a[(inda+1)%n1]) >=0) {
    //              printf("no its this one\n");
                    inda = (inda + 1) % n1; 
                    
        }

        while (orientation(a[inda], b[indb], b[(n2+indb-1)%n2]) <=0) 
        {   
            indb = (n2+indb-1)%n2; 
            done = 0; 
            //printf("is this error\n");
        } 
    } 
//  printf("line 106\n");
    long long int uppera = inda;
    long long int upperb = indb; 
    inda = ia;
    indb=ib; 
    done = 0; 
    long long int g = 0; 
    if(n1==0 || n2==0){
        done=1;
    }
    while (!done)//finding the lower tangent 
    { 
        done = 1; 
        while (orientation(a[inda], b[indb], b[(indb+1)%n2])>=0) 
            indb=(indb+1)%n2; 

        while (orientation(b[indb], a[inda], a[(n1+inda-1)%n1])<=0) 
        { 
            inda=(n1+inda-1)%n1; 
            done=0; 
        } 
    } 
    //printf("merger\n");
    long long int lowera = inda;
    long long int lowerb = indb; 
    vector<pair<double,double>> ret; 

    //ret contains the convex hull after merging the two convex hulls 
    //with the points sorted in anti-clockwise order 
    long long int ind = uppera; 
    ret.push_back(a[uppera]); 
    while (ind != lowera) 
    { 
        ind = (ind+1)%n1; 
        ret.push_back(a[ind]); 
    } 

    ind = lowerb; 
    ret.push_back(b[lowerb]); 
    while (ind != upperb) 
    { 
        ind = (ind+1)%n2; 
        ret.push_back(b[ind]); 
    } 
    return ret; 

} 
vpdd hull_quick;

// Brute force algorithm to find convex hull for a set 
// of less than 6 points 
bool ccw(pdd a, pdd b, pdd c)
{
    return ((c.first - a.first) * (b.second - a.second) - (c.second - a.second) * (b.first - a.first)) < 0;
}
vpdd jarvis_march(const vpdd &input)
{

    int n = input.size();
    vpdd hull_jmarch;
    if(n<3){
        hull_jmarch.push_back(make_pair(-1,-1));
    
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




// Returns the convex hull for the given set of points 
vector<pair<double, double>> divide(vector<pair<double,double>> a) 
{ 
    // If the number of points is less than 6 then the 
    // function uses the brute algorithm to find the 
    // convex hull 
    if (a.size() <= 10) {
        
        return jarvis_march(a); 
    }

    // left contains the left half points 
    // right contains the right half points 
    vector<pair<double,double>>left, right; 
    for (long long int i=0; i<a.size()/2; i++) 
        left.push_back(a[i]); 
    for (long long int i=a.size()/2; i<a.size(); i++) 
        right.push_back(a[i]); 

    // convex hull for the left and right sets 
    vector<pair<double,double>>left_hull = divide(left); 
    vector<pair<double,double>>right_hull = divide(right); 
    //printf("completed till here\n");
    // merging the convex hulls 
    return merger(left_hull, right_hull); 
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
        op1 = "outputs_100/output_dc_convexhull"+to_string(j)+".txt";
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
        //Point *input1 = new Point[t];
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
            //input1[i].x = temp1;
            //input1[i].y = temp2;
        }

    sort(input.begin(),input.end());
    
	clock_gettime(CLOCK_REALTIME,&start);
	vpdd output=divide(input);
	clock_gettime(CLOCK_REALTIME,&end);

    // sort(output.begin(),output.end());
	file2 << output.size() << "\n";
        for (auto &i : output)
        {
            file2 << i.first << ", " << i.second << "\n";
        }
        double time=time_elapsed(&start,&end);
        file2 << time;
	}

	for(int j=1;j<=16;j++){

//	cin >> N;
	//scanf("%lld",&N);
	//cout << N << endl;
//	printf("%lld\n",N );
	string inp1,op1;
        inp1 = "inputs_1000/input"+to_string(j)+".txt";
        op1 = "outputs_1000/output_dc_convexhull"+to_string(j)+".txt";
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

    sort(input.begin(),input.end());
    
	clock_gettime(CLOCK_REALTIME,&start);
	vpdd output=divide(input);
    clock_gettime(CLOCK_REALTIME,&end);

    // sort(output.begin(),output.end());

	file2 << output.size() << "\n";
        for (auto &i : output)
        {
            file2 << i.first << ", " << i.second << "\n";
        }
        double time=time_elapsed(&start,&end);
        file2 << time;
	}
	for(int j=1;j<=16;j++){

//	cin >> N;
	//scanf("%lld",&N);
	//cout << N << endl;
//	printf("%lld\n",N );
	string inp1,op1;
        inp1 = "inputs_10000/input"+to_string(j)+".txt";
        op1 = "outputs_10000/output_dc_convexhull"+to_string(j)+".txt";
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
        sort(input.begin(),input.end());
    
    
	clock_gettime(CLOCK_REALTIME,&start);
	vpdd output=divide(input);
    clock_gettime(CLOCK_REALTIME,&end);
    // sort(output.begin(),output.end());
	file2 << output.size() << "\n";
        for (auto &i : output)
        {
            file2 << i.first << ", " << i.second << "\n";
        }
        double time=time_elapsed(&start,&end);
        // file2 << std::setprecision(9) << std::showpoint << std::fixed;
        file2 << time;
	}
	return 0;
}
