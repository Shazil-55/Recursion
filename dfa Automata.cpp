//#include <iostream>
//using namespace std;
//int main()
//{
//	int dfa[3][2] = {0,1,0,2,0,2};
//	int final_state[] = { 2 };
//	string alpha;
//	cout << " enter the string you want to check ";
//	cin >> alpha;
//	int l = 0;
//	int arr[10];
//	while (alpha[l] != '\0')
//	{
//		arr[l] =(int)alpha[l];
//		if (arr[l] == 48)arr[l] -= 48;
//		else if (arr[l] == 49)arr[l] -= 48;
//		cout << arr[l] << " ";
//		l++;
//	}
//
//	int curr_state = dfa[0][0];
//	
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cout << dfa[i][j];
//		}cout << endl;
//	}
//	for ( int i =0 ; i<5 ; i++)
//	{
//		//cout << curr_state << "  ";
//		cout << dfa[0][arr[i]] << " ";
//		curr_state = dfa[curr_state][arr[i]];
//		
//	}
//	for (int i = 0; i < 1; i++)
//	{
//		if (curr_state == final_state[i])
//		{
//			cout << " this string will be accepted ";
//			return 0;
//		}
//	}
//	cout << " this string wasn't accepted ";
//	return 0;
// }