#include <iostream>
using namespace std;

double P0(const int K, const int N) {
    if (K > N) {
        return 1.0;
    }
    if (K == 0 && N == 0) {
        return 1.0;
    }

    double product = 1.0;
    for (int i = K; i <= N; i++) {
        product *= (K / static_cast<double>(i) + i / static_cast<double>(N));
    }
    return product;
}

double P1(const int K, const int N, const int i) {
    if (K > N) {
        return 1.0;
    }
    if (K == 0 && N == 0) {
        return 1.0;
    }
    if (i > N) {
        return 1.0;
    }
    return (K / static_cast<double>(i) + i / static_cast<double>(N)) * P1(K, N, i + 1);
}

double P2(const int K, const int N, const int i) {
    if (K > N) {
        return 1.0;
    }
    if (K == 0 && N == 0) {
        return 1.0;
    }
    if (i < K) {
        return 1.0;
    }
    return (K / static_cast<double>(i) + i / static_cast<double>(N)) * P2(K, N, i - 1);
}

double P3(const int K, const int N, const int i, double t) {
    if (K > N) {
        return 1.0;
    }
    if (K == 0 && N == 0) {
        return 1.0;
    }
    t *= (K / static_cast<double>(i) + i / static_cast<double>(N));
    if (i >= N) {
        return t;
    }
    else {
        return P3(K, N, i + 1, t);
    }
}

double P4(const int K, const int N, const int i, double t) {
    if (K > N) {
        return 1.0;
    }
    if (K == 0 && N == 0) {
        return 1.0;
    }
    t *= (K / static_cast<double>(i) + i / static_cast<double>(N));
    if (i <= K) {
        return t;
    }
    else {
        return P4(K, N, i - 1, t);
    }
}

int main() {
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;

    cout << "(iter) P0 = " << P0(K, N) << endl;
    cout << "(rec up ++) P1 = " << P1(K, N, K) << endl;
    cout << "(rec up --) P2 = " << P2(K, N, N) << endl;
    cout << "(rec down ++) P3 = " << P3(K, N, K, 1) << endl;
    cout << "(rec down --) P4 = " << P4(K, N, N, 1) << endl;

    return 0;
}
