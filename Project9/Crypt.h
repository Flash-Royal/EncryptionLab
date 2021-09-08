using namespace std;
void cezar(string& s, string& s1, int& key)
{
	int n = 0;
	string s2;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != ' ') {
			n++;
			s2 += s1[i];
		}
	}
	int* k = new int[n];
	int* k1 = new int[n];
	for (int i = 0; i < n; i++) {
		k[i] = i;
	}
	for (int i = 0; i < n; i++) {
		k1[i] = k[i] + key;
		while (k1[i] < 0 || k1[i] > n - 1) {
			if (k1[i] < 0) { k1[i] = k1[i] + n; }
			else {
				if (k1[i] > n - 1) {
					k1[i] = k1[i] - n;
				}
			}
		}
	}
	string s3;
	string s4;
	s3 = s;
	int m = s.size();
	for (int v = 0; v < s2.size(); v++) {
		while (s.find(s2[v]) != -1) {
			int l = s.find(s2[v]);
			s3[l] = s2[k1[v]];
			for (int j = 0; j < s.size(); j++) {
				if (j != l) {
					s4 += s[j];
				}
				else { s4 = s4 + ' '; }
			}
			s = s4;
			s4.clear();
		}
	}
	s = s3;
}
int binary(int val) {
	int val1 = 0;
	int val2 = 0;
	int i = 0;
	while (val != 0) {
		val1 = val % 2;
		val = val / 2;
		val2 += pow(10, i)*val1;
		i++;
	}
	return val2;
}
int binary_size(int val) {

	int val1 = 0;
	int n = 0;
	val1 = binary(val);
	if (val1 == 0) {
		n = 1;
	}
	else {
		while (val1 != 0) {
			val1 = val1 / 10;
			n++;
		}
	}
	return n;
}
void vegener(string& s, string& s1, string& key) {
	string s2;
	string s3;
	int n = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != ' ') {
			n++;
			s2 += s1[i];
		}
	}
	int** k = new int*[key.size()];
	for (int i = 0; i < key.size(); i++) {
		k[i] = new int[s2.size()];
		for (int j = 0; j < s2.size(); j++) {
			k[i][j] = j;
		}
	}
	int* key1 = new int[key.size()];
	for (int i = 0; i < key.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (key[i] == s2[j]) {
				key1[i] = j;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < key.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			k[i][j] = k[i][j] + key1[i];
			while (k[i][j] >= s2.size()) {
				k[i][j] = k[i][j] - s2.size();
			}
		}
	}
	string s4;
	s3 = s;
	s4 = s;
	int m = 0;
	for (int i = 0; i < s2.size(); i++) {
		while (s4.find(s2[i]) != -1) {
			int l = s4.find(s2[i]);
			s3[l] = s2[k[l % (key.size())][i]];
			s4[l] = ' ';
		}
	}
	s = s3;
}
void rc4_code(string& s3, string& alf, int*& key_1) {
	vector<char> s;
	vector<string> s1;
	vector<int> k;
	int m = 0;
	int n = 0;
	for (int i = 0; i < alf.size(); i++) {
		if (alf[i] != ' ') {
			m++;
		}
	}
	s1.reserve(m);
	s.reserve(m);
	k.reserve(m);
	for (int i = 0; i < alf.size(); i++) {
		if (alf[i] != ' ') {
			s.push_back(alf[i]);
		}
	}
	for (int i = 0; i < m; i++) {
		k.push_back(binary(i));
	}
	string s2;
	for (int i = 0; i < m; i++) {
		for (int j = binary_size(i); j < binary_size(m - 1); j++) {
			s2 += "0";
		}
		s1.push_back(s2 + to_string(k[i]));
		s2.clear();
	}
	int l = 256;
	int* s6 = new int[l];
	for (int i = 0; i < l; i++) {
		s6[i] = i;
	}
	int j = 0;
	int temp;
	for (int i = 0; i < l; i++) {
		j = (j + s6[i]) % 256;
		temp = s6[i];
		s6[i] = s6[j];
		s6[j] = temp;
	}
	j = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < s.size(); j++) {
			while (s3.find(s[i]) != -1) {
				string s4;
				int k = s3.find(s[i]);
				for (int l = 0; l < k; l++) {
					s4 += s3[l];
				}
				s4 = s4 + s1[i];
				for (int l = k + 1; l < s3.size(); l++) {
					s4 += s3[l];
				}
				s3 = s4;
				s4.clear();
			}
		}
	}
	int u;
	int* k2 = new int[s3.size()];
	string s7;
	key_1 = new int[s3.size()];
	for (int i = 0; i < s3.size(); i++) {
		if (s3[i] != ' ') {
			j = (j + s6[i]) % 256;
			u = s6[(s6[j] + s6[i]) % 256] % 2;
			k2[i] = u;
			if ((s3[i] == '0') && (u == 0)) {
				s7 += '0';
			}
			else {
				if ((s3[i] == '0') && (u == 1)) {
					s7 += '1';
				}
				else {
					if ((s3[i] == '1') && (u == 0)) {
						s7 += '1';
					}
					else {
						if ((s3[i] = '1') && (u = 1)) {
							s7 += '0';
						}
					}
				}
			}
		}
		else {
			s7 += ' ';
		}
	}
	int o = 0;
	string s8;
	string s9;
	for (int i = 0; i < s7.size(); i++) {
		if (s7[i] != ' ') {
			for (int j = 0; j < s1[0].size(); j++) {
				s8 += s7[i];
				i++;
			}
			o = 0;
			for (int k = 0; k < m; k++) {
				if (s8 == s1[k]) {
					s9 += s[k];
					o = 1;
					break;
				}
			}
			if (o == 0) {
				s9 += s8;
			}
			i--;
			s8.clear();
		}
		else {
			s9 += ' ';
		}
	}
	cout << s3 << endl;
	for (int i = 0; i < s3.size(); i++) {
		key_1[i] = k2[i];
	}
	s3 = s9;

}

