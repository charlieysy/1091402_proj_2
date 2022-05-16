#include<iostream>
#include <iomanip>
using namespace std;

string StateDiagram[8] = { "SN0","WN1","WN2","WN3","WT3","WT2","WT1","ST" };
string history = "000";
int counter[8] = {};

int main() {
	string pattern;
	cin >> pattern;		// TTTTNNTNTNTNTNTNT
	cout<<"\nPredictor state" << setw(29) << "outcome" << setw(13) << "prediction" << setw(9) << "miss?" << endl;

	for (int i = 0;i < pattern.size();i++) {

		int count = 0;
		for (int j = i - 3;j <= i - 1;j++) {
				if (j < 0)
					history[count] = '0';
				else if (pattern[j] == 'T')
					history[count] = '1';
				else
					history[count] = '0';
				count++;
		}
		cout << history << " ";

		for (int j = 0; j <= 7; j++) {
			cout << StateDiagram[counter[j]]<<" ";
		}
		cout <<setw(5)<< pattern[i]<<setw(11);

		int decimal = (int(history[0]) - 48) * 4 + (int(history[1]) - 48) * 2 + (int(history[2]) - 48) * 1;
		if (counter[decimal] == 0 || counter[decimal] == 1 || counter[decimal] == 2 || counter[decimal] == 3) {
			cout << "N";
			if (pattern[i] == 'N') {
				cout << setw(15) << "not miss";
				if(counter[decimal] != 0)
					counter[decimal]--;
			}
			else {
				cout << setw(13) << "miss";
				counter[decimal]++;
			}
		}
		else {
			cout << "T";
			if (pattern[i] == 'T') {
				cout <<setw(15)<< "not miss";
				if (counter[decimal] != 7)
					counter[decimal]++;
			}
			else {
				cout << setw(13) << "miss";
				counter[decimal]--;
			}
		}
		cout << endl;
	}
}
