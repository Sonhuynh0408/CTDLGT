#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa 4 hướng di chuyển: Trái, Phải, Lên, Xuống
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Hàm BFS tìm đường đi ngắn nhất
vector<pair<int, int>> timDuongDi(vector<vector<int>> &meCung, int N, int M, int x0, int y0, int x1, int y1) {
    queue<pair<int, int>> hangDoi;
    vector<vector<bool>> daTham(N, vector<bool>(M, false));
    vector<vector<pair<int, int>>> truyVet(N, vector<pair<int, int>>(M, {-1, -1}));

    // Đưa điểm bắt đầu vào hàng đợi
    hangDoi.push({x0, y0});
    daTham[x0][y0] = true;

    while (!hangDoi.empty()) {
        auto [x, y] = hangDoi.front();
        hangDoi.pop();

        // Nếu đến đích thì dừng
        if (x == x1 && y == y1) {
            vector<pair<int, int>> duongDi;
            while (!(x == x0 && y == y0)) {
                duongDi.push_back({x, y});
                tie(x, y) = truyVet[x][y];
            }
            duongDi.push_back({x0, y0});
            reverse(duongDi.begin(), duongDi.end());
            return duongDi;
        }

        // Kiểm tra 4 hướng di chuyển
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && meCung[nx][ny] == 0 && !daTham[nx][ny]) {
                hangDoi.push({nx, ny});
                daTham[nx][ny] = true;
                truyVet[nx][ny] = {x, y};
            }
        }
    }

    return {}; // Không tìm thấy đường đi
}

int main() {
    int N, M, x0, y0, x1, y1;
    cin >> N >> M >> x0 >> y0 >> x1 >> y1;

    vector<vector<int>> meCung(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> meCung[i][j];

    vector<pair<int, int>> ketQua = timDuongDi(meCung, N, M, x0, y0, x1, y1);

    if (ketQua.empty()) {
        cout << "0\n";
    } else {
        cout << ketQua.size() << "\n";
        for (auto [u, v] : ketQua) {
            cout << u << " " << v << "\n";
        }
    }

    return 0;
}
