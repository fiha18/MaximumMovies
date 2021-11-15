#include <bits/stdc++.h>

using namespace std;

vector<string> simple_tokenizer(string s)
{
	vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}


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

	for (int i = 0; i < n; ++i)
	{
		/* code */
		cout << movies[i] << ": from " << dateToInt(months[i].first,days[i].first)<<" to "<<dateToInt(months[i].second,days[i].second)<< endl;
	}
	return 0;
}