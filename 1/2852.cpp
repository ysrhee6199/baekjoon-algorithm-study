#include "bits/stdc++.h"
using namespace std;

int winning_time_min[2];
int winning_time_sec[2];
int score[2];
int cur_min,cur_sec;

string make_string(int a)
{
    string s;
    if(a <10 && a >=0)
    {
        s = "0";
        s += to_string(a);
    }
    else s = to_string(a);

    return s;
}

void calc_time(int time_min, int time_sec, int team_) 
{
    int start_total_sec = cur_min * 60 + cur_sec;
    int end_total_sec = time_min * 60 + time_sec;

    int tmp = end_total_sec - start_total_sec;

    int tmp_sec = tmp % 60;
    int tmp_min = tmp / 60;


    int add_min = 0;
    winning_time_sec[team_] += tmp_sec;
    if(winning_time_sec[team_] >= 60) 
    {
        winning_time_sec[team_] -= 60;
        add_min = 1;
    }
    winning_time_min[team_] += tmp_min + add_min;    
}

void timeline_(int team_,string time_)
{
    int time_min = stoi(time_.substr(0,2));
    int time_sec = stoi(time_.substr(3));
    if(score[0] > score[1])
    {
        calc_time(time_min,time_sec,0);
    }
    else if (score[1] > score[0])
    {
        calc_time(time_min,time_sec,1);
    }
    cur_min = time_min;
    cur_sec = time_sec;
    score[team_-1]++;
}

int main() 
{
    int cnt = 0;
    cin >> cnt;

    for(int i =0; i<cnt; i++) 
    {
        int team_;
        string time_;
        cin >> team_ >> time_;

        timeline_(team_,time_);
    }

    if(score[0] != score[1]) calc_time(48,0,score[0] > score[1] ? 0 : 1);

    for(int i =0; i<2; i++)
    {
        string min_ = make_string(winning_time_min[i]);
        string sec_ = make_string(winning_time_sec[i]);
        cout << min_ << ":" << sec_ <<"\n";
    }

    return 0;
}