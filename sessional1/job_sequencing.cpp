#include <bits/stdc++.h>
using namespace std;

struct Job{
	int deadline;
	int profit;
	string id;
};

struct Slot{
	int job_idx;
	bool filled;
};

void greedy(vector<Job>& jobs){
	int n = jobs.size();
	sort(jobs.begin(), jobs.end(), [](Job a, Job b){
		return a.profit>b.profit;
	});
	int maxDeadline = 0;
	for(int i=0;i<jobs.size();i++)
		if(jobs[i].deadline>maxDeadline)
			maxDeadline = jobs[i].deadline;
	vector<Slot> slots(maxDeadline+1);
	for(int i=0; i<n; i++){
		for(int j=min(maxDeadline, jobs[i].deadline); j>=1; j--){
			if(slots[j].filled==false){
				slots[j].filled = true;
				slots[j].job_idx = i;
				break;
			}
		}
	}
	for(int i=1;i<slots.size();i++){
		if(slots[i].filled){
			cout << jobs[slots[i].job_idx].id << " ";
		}
	}
}	

int main(){
	int n;
	cout << "Enter number of jobs: ";
	cin >> n;
	vector<Job> jobs(n);
	for(int i=0;i<n;i++){
		cout << "Enter deadline and profit of job " << i+1 << ": ";
		cin >> jobs[i].deadline >> jobs[i].profit;
		jobs[i].id = "J" + to_string(i+1);
	}
	greedy(jobs);
	cout << endl;
	return 0;
}
