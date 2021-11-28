#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using ll = long long;

vector<int> qeens;
ll result;

void solve(const ll& N, int put) {
    if (N == put) {
        result += 1;
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        bool isOk{ true };
        // (put, i)�� ���� ���� �� �ִ��� Ȯ���Ѵ�
        // ���� �� �ٿ� �ϳ��� ���ƾ� �ϱ� ������ ���⼭ �����ϸ� ���� i�� �Ѿ��
        for (int j = 0; j < put; ++j)
        {
            if (i == qeens[j] || abs(put - j) == abs(i - qeens[j])) {
                isOk = false;
                break;
            }
        }

        if (isOk) {
            qeens[put] = i;
            solve(N, put + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll N;
    cin >> N;

    qeens = vector<int>(N, -1);
    result = 0;

    solve(N, 0);
    cout << result;

    return 0;
}