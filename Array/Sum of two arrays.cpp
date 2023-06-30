#include <bits/stdc++.h> 
void reverse(vector<int>& ans){
	int s = 0;
	int e = ans.size() - 1;

	while(s <= e){
		swap(ans[s++], ans[e--]);
	}
}
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n - 1;
	int j = m - 1; 
	vector<int> ans;
	int carry = 0;

	while(i >= 0 && j >= 0){
		int val1 = a[i];
		int val2 = b[j];

		int sum = val1 + val2 + carry;
		//differentiate the carry from rest of the sum
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
		j--;
	}

	//1st case -> elements in a > elements in b
	while(i >= 0){
		int sum = a[i] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
	}

	//2nd case -> elements in a < elements in b
	while(j >= 0){
		int sum = b[j] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		j--;
	}

	//3rd case-> carry has come
	while(carry != 0){
		int sum = carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
	}

	reverse(ans);
	return ans;
}
