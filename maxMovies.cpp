#include <bits/stdc++.h>

using namespace std;

int dateToInt(string month, int day)
{
	unordered_map<string,int> map;
	map["Jan"] = 1;
	map["Feb"] = 2;
	map["Mar"] = 3;
	map["Apr"] = 4;
	map["May"] = 5;
	map["Jun"] = 6;
	map["Jul"] = 7;
	map["Aug"] = 8;
	map["Sep"] = 9;
	map["Oct"] = 10;
	map["Nov"] = 11;
	map["Dec"] = 12;
	int intDate = map[month]*100 + day;
	return intDate;
}
bool sortBySecond(pair<int, int>& a,
                pair<int, int>& b)
{
    return (a.second < b.second);
}
void maxMovie(vector<pair<int,int>> intervals)
{
	// Sort the intervals according to the endDate of the interval
	sort(intervals.begin(), intervals.end(), sortBySecond);
	int count = 1;	// After sorting the first interval will be included for Greedy approach
	//End date of first interval for the actor
	int endDate1 = intervals[0].second;
	for (int i = 1; i < intervals.size(); ++i)
	{

		int startDate2 = intervals[i].first;
		int endDate2 = intervals[i].second;
		// If this interval does not overlapp with the previous interval then it is included and count is increased
		if(startDate2 > endDate1)
		{
			count++;
			endDate1 =endDate2;
		} 
	}
	if( count > 1)
	{
		cout << count <<" Crores" << endl;
	}
	else
		cout << count <<" Crore" << endl;


}


int main()
{
	int n ;
	cin >> n;
	vector<pair<int,int>> days;
	vector<pair<string,string>> months;
	vector<string> movies;
	for (int i = 0; i < n; ++i)
	{
		string movie;
		cin >> movie;
		movies.push_back(movie);
		int startDay;
		string startMonth;
		cin >>startDay>>startMonth;
		int endDay;
		string endMonth;
		cin >> endDay >> endMonth;
		days.push_back(make_pair(startDay,endDay));
		months.push_back(make_pair(startMonth,endMonth));
	}
	vector<pair<int,int>> dates(n);
	for (int i = 0; i < n; ++i)
	{
		dates[i] = make_pair(dateToInt(months[i].second,days[i].first),dateToInt(months[i].second,days[i].second));
	}
	
	maxMovie(dates);
	return 0;
}