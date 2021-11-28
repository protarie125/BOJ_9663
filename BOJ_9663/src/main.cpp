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
        // (put, i)에 퀸을 놓을 수 있는지 확인한다
        // 퀸을 한 줄에 하나는 놓아야 하기 때문에 여기서 실패하면 다음 i로 넘어간다
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