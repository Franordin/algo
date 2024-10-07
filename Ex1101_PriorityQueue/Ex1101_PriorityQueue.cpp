#include <iostream>
#include <queue>
using namespace std;

int main() {
    // C++ 우선순위 큐 std::priority_queue 사용법

    // 기본 설정은 큰 값의 우선순위가 높은 max queue
    {
        priority_queue<double> max_queue;

        for (double v : vector<double>{ 3.5, 2.4, 8.3, 9.9, 1.2, 3.9 })
            max_queue.push(v);

        // 큰 값부터 출력
        while (!max_queue.empty()) {
            cout << max_queue.top() << " ";
            max_queue.pop();
        }
        cout << endl;
    }

    // 작은 값의 우선순위가 높은 min queue
    {
        // double -> 저장될 자료형
        // vector<double> -> priority queue에서 내부적으로 사용할 컨테이너
        // greater<double> -> 우선순위를 결정할 때 사용할 비교
        // greate<double> 대신에 less<double>을 사용하면 max queue
        // std::greater<int> makes the max priority queue act as a min priority queue
        priority_queue<double, vector<double>, greater<double>> min_queue;

        for (auto v : vector<double>{ 3.5, 2.4, 8.3, 9.9, 1.2, 3.9 })
            min_queue.push(v);

        // 작은 값부터 출력
        while (!min_queue.empty()) {
            cout << min_queue.top() << " ";
            min_queue.pop();
        }
        cout << endl;
    }

    // 우선순위 큐에 std::pair<double, int> 저장
    // double형 변수 하나와 int형 변수 하나를 묶어 놓은 쌍(pair)
    // 중복 저장 가능: {3.5, 1}이 여러 번 저장됨.
    {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

        for (pair<double, int> v : vector<pair<double, int>>{ {3.5, 3}, {8.3, 1}, {3.5, 1}, {3.5, 2}, {2.4, 8}, {8.3, 5}, {3.5, 1}, {3.5, 1} })
            pq.push(v);
        
        // pair에서 double값이 같으면 int값이 작은 쪽 먼저 출력
        while (!pq.empty()) {
            cout << "(" << pq.top().first << ", " << pq.top().second << ") ";
            // first: pair에서 첫 번째(여기서는 double형)
            // second: pair에서 두 번째(여기서는 int형)

            pq.pop();
        }
        cout << endl;
    }

    return 0;
}