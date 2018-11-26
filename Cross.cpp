#include <iostream>
#include <cmath>
using namespace std;


bool ok(int cross[8], int c){
	static int a[][5] = {  // sets up the adjecency array
      {-1},
      {0, -1},
      {0, 1, -1},
      {0, 2, -1},
      {1, 2, -1},
      {1, 2, 3, 4, -1},
      {2, 3, 5, -1},
      {4, 5, 6, -1}
    };

	for (int i = 0; i < c; ++i)   // tests if the same number has been placed
		if (cross[i] == cross[c])
     return false;


	for (int i = 0; a[c][i] != -1; ++i){
		if (1 == abs( cross[c] - cross[a[c][i]])) //tests if edjacent squares are off by 1
     return false;
	}
	return true;
}

void backtrack (int &c){
	--c;           // go back one column
	if (c == -1){
		exit(1);    // exit if all the solutions are found
	}
}

void print ( int cross[] ){
	static int count = 0;
	cout << "Solution #" << ++count << endl;
  cout << "  " <<cross[0]+1 <<" "<<cross[1]+1<< " "<< endl;
  cout << cross[2]+1 <<" "<<cross[3]+1 <<" "<<cross[4]+1<<" "<<cross[5]+1<< ' '<< endl;
  cout << "  " <<cross[6]+1 <<" "<<cross[7]+1<< " "<< endl;
}

int main(){
	int cross[8], c = 0;
	bool from_backtrack = false;
	while (true){
		while (c < 8){
			if (!from_backtrack)
			cross[c] = -1;
			from_backtrack = false;

			while (cross[c] < 8 ){
				cross[c]++;
				if (cross[c] == 8 ){
					backtrack(c);
					continue;
				}
				if (ok(cross, c)) break;
			}
			c++;
		}
		print (cross);
		backtrack (c);
		from_backtrack = true;
	}
}
