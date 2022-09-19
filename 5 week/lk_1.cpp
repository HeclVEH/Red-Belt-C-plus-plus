#include "profile.h"

#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <set>
#include <map>
#include <array>

#include <utility>
#include <string_view>

using namespace std;

vector<string> ReadStrings(istream& stream, bool use_move) {
	vector<string> strings;
	string s;
	while (stream >> s) {
		if (use_move) {
			strings.push_back(move(s));
		}
		else {
			strings.push_back(s);
		}		
	}
	return strings;
}

string GenerateText() {
	const int SIZE = 1'00'000'000;
	const int WORD_LENGTH = 10'000'000;
	string text(SIZE, 'a');
	for (int i = WORD_LENGTH; i < SIZE; i += WORD_LENGTH) {
		text[i] = ' ';
	}
	return text;
}

string MakeString() {
	return string(100'000'000, 'a');
}

vector<int> MakeVector() {
	return vector<int>(100'000'000, 0);
}

vector<string> SplitIntoWords(const string& text) {
	vector<string> words;
	string current_word;
	for (const char c : text) {
		if (c == ' ') {
			words.push_back(move(current_word));
			current_word.clear();
		}
		else {
			current_word.push_back(c);
		}
	}	
	words.push_back(current_word);
	return words;
}

int main1() {
	{
		LOG_DURATION("with var");
		vector<string> strings;
		string heavy_string = MakeString();
		strings.push_back(heavy_string);
	}
	{
		LOG_DURATION("without var");
		vector<string> strings;		
		strings.push_back(MakeString());
	}
	{
		LOG_DURATION("constr: with var");
		vector<string> strings;
		string heavy_string = string(100'000'000, 'a');
		strings.push_back(heavy_string);
	}
	{
		LOG_DURATION("constr: without var");
		vector<string> strings;
		strings.push_back(string(100'000'000, 'a'));
	}
	return 0;
}

int main2() {
	{
		LOG_DURATION("assignment, with variable");
		string target_string = "old value";
		string source_string = MakeString();
		target_string = source_string;
	}
	{
		LOG_DURATION("assignment, without variable");
		string target_string = "old value";	
		target_string = MakeString();
	}
	{
		LOG_DURATION("set::insert, with variable");
		set<string> strings;
		string heavy_string = MakeString();
		strings.insert(heavy_string);		
	}
	{
		LOG_DURATION("set::insert, without variable");
		set<string> strings;	
		strings.insert(MakeString());
	}
	{
		LOG_DURATION("map::operator[], with variable");
		map<string,string> strings;
		string key = MakeString();
		string value = MakeString();
		strings[key] = value;		
	}
	{
		LOG_DURATION("map::operator[], without variable");
		map<string, string> strings;		
		strings[MakeString()] = MakeString();
	}
	{
		LOG_DURATION("set::insert for vector, with variable");
		set<vector<int>> vectors;
		vector<int> heavy_vector = MakeVector();
		vectors.insert(heavy_vector);
	}
	{
		LOG_DURATION("set::insert for vector, without variable");
		set<vector<int>> vectors;
		vectors.insert(MakeVector());
	}
	return 0;
}

int main3() {
	/*{
		for (const string& s : ReadStrings(cin,true)) {
			cout << s << "\n";
		}
	}*/
	const string text = GenerateText();
	{
		LOG_DURATION("without move");
		istringstream stream(text);
		ReadStrings(stream, false);
	}
	{
		LOG_DURATION("with move");
		istringstream stream(text);
		ReadStrings(stream, true);
	}
	
	return 0;
}

int main4() {
	for (const string& word : SplitIntoWords("Red belt c++")) {
		cout << word << "\n";
	}
	return 0;
}

const int SIZE = 10000;
array<int, SIZE> MakeArray() {
	array<int, SIZE> a;
	a.fill(8);
	return a;
}

string MakeStringC() {
	return "C++";
}

int main() {
	/*{
		LogDuration a("with var");
		LOG_DURATION("with variable");
		vector<array<int, SIZE>> arrays;
		for (int i = 0; i < 10000; ++i) {
			auto heavy_array = MakeArray();
			arrays.push_back(heavy_array);
		}
	}
	{
		LogDuration a("without var");
		LOG_DURATION("without variable");
		vector<array<int, SIZE>> arrays;	
		for (int i = 0; i < 10000; ++i) {
			arrays.push_back(MakeArray());
		}
	}*/
	{
		vector<string> strings;
		const string s = MakeStringC();
		cout << s << "\n";
		strings.push_back(move(s));
		cout << s << "\n";
	}
	return 0;
}