#include <iostream>
#include <vector>
#include <bitset>
#include <iomanip>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve (ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int) i);
	}
}


vi primeFactors(ll N) {
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) {
		while (N % PF == 0) { N /= PF; factors.push_back(PF); }
		PF = primes[++PF_idx];
	}
	if (N != 1) factors.push_back(N);
	return factors;
}

int main(void) {
	sieve(10000000);
	int c; 
	cin>>c;
	while(c--) {
		int n;
		cin >> n;
		vi primesF = primeFactors(n);
		ll numerador = 0;
		ll denominador = 0;
		for (int i = 0; i < primesF.size(); i++) {
			numerador += (primesF[i] - 1); 
			denominador += primesF[i];
		}
		ll coprimes = ((ll)(n)*numerador / denominador);
		cout<<coprimes << " " <<fixed <<setprecision(4)<<((double)coprimes/2)<<endl;
	}
	return 0;
}
