#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> bs;
vi primes;
vi coprimes;

void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int) i);
	}
}

void sieveCo(ll upperbound) {
	coprimes.clear();
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 0; i < primes.size(); i++) {
		prime = primes[i];
		bs[prime] = 1;
	}
}

int main(void) {
	sieve(10000000);
	sieveCo(10);
	cout << "Coprimes" << coprimes.size() << endl;
	for(int i = 0; i < coprimes.size(); i++) {
		cout<<coprimes[i]<<" ";
	}
	cout<<endl;
	return 0;
}
