#include <bits/stdc++.h>
using namespace std;

struct Activity{
	int st;
	int et;
	string id;
};

void greedy1(vector<Activity>& activities){
	cout << "Greedy 1 by sorting according to smallest activity: ";
	sort(activities.begin(), activities.end(), [](Activity a, Activity b){
		return (a.et-a.st)>(b.et-b.st);
	});
	vector<Activity> selected;
	selected.push_back(activities[0]);
	for(int i=1; i<activities.size(); i++){
		bool flag = true;
		for(int j=0; j<selected.size(); j++){
			if(activities[i].st<selected[j].et && activities[i].et>selected[j].st){
				flag = false;
				break;
			}
		}
		if(flag){
			selected.push_back(activities[i]);
		}
	}
	for(int i=0;i<selected.size();i++){
		cout << selected[i].id << " ";
	}
}

void greedy2(vector<Activity>& activities){
	cout << "Greedy 2 by sorting according to activity that overlaps with least number of activities: ";
	vector<int> overlaps(activities.size(), 0);
	for(int i=0; i<activities.size(); i++){
		for(int j=i+1; j<activities.size(); j++){
			if(activities[i].st<activities[j].et && activities[i].et>activities[j].st){
				overlaps[i]++;
				overlaps[j]++;
			}
		}
	}
	sort(activities.begin(), activities.end(), [&overlaps](Activity a, Activity b){
		return overlaps[a.id[1]-'0'-1]<overlaps[b.id[1]-'0'-1];
	});
	vector<Activity> selected;
	selected.push_back(activities[0]);
	for(int i=1; i<activities.size(); i++){
		bool flag = true;
		for(int j=0; j<selected.size(); j++){
			if(activities[i].st<selected[j].et && activities[i].et>selected[j].st){
				flag = false;
				break;
			}
		}
		if(flag){
			selected.push_back(activities[i]);
		}
	}
	for(int i=0;i<selected.size();i++){
		cout << selected[i].id << " ";
	}
}

void greedy3(vector<Activity>& activities){
	cout << "Greedy 3 by sorting according to earliest finish time:";
	sort(activities.begin(), activities.end(), [](Activity a, Activity b){
		return a.et<b.et;
	});
	vector<Activity> selected;
	selected.push_back(activities[0]);
	for(int i=1; i<activities.size(); i++){
		if(activities[i].st>=selected[selected.size()-1].et){
			selected.push_back(activities[i]);
		}
	}
	for(int i=0;i<selected.size();i++){
		cout << selected[i].id << " ";
	}
}

int main(){
	int n;
	cout << "Enter no of activities: ";
	cin >> n;
	vector<Activity> activities(n);
	for(int i=0;i<n;i++){
		cout << "Enter start time and end time of activity " << i+1 << ": ";
		cin >> activities[i].st >> activities[i].et;
		activities[i].id = "A" + to_string(i+1);
	}
	greedy1(activities);
	cout << endl;
	greedy2(activities);
	cout << endl;
	greedy3(activities);
	return 0;
}