#include <bits/stdc++.h>
#include <sys/time.h>
 
#ifdef LOCAL
#include "../headers/logger.hpp"
#define LOG_TC(...) LOG_INFO(__VA_ARGS__);
#else
#define LOG_DEBUG(...);
#define LOG_INFO(...);
#define LOG_WARNING(...);
#define LOG_ERROR(...);
#define LOG_TC(...) {fprintf(stderr, __VA_ARGS__);fprintf(stderr, "\n"); }
#define PANIC(...);
#define ASSERT(...);
#endif
 
static inline double get_time() {
  timeval tv;
  gettimeofday(&tv, 0);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}
 
const double END_TIME = 4.95;
double start_time = get_time();
double end_time = start_time + END_TIME;
 
struct rand_gen {
  static constexpr uint32_t kMax = 2147483647;
  static constexpr double kInvMax = 1.0 / (double)kMax;
  static constexpr __uint128_t kAdd = 0x60bee2bee120fc15ull;
  static constexpr __uint128_t kMul1 = 0xa3b195354a39b70dull;
  static constexpr __uint128_t kMul2 = 0x1b03738712fad5c9ull;
  uint64_t state = 3;
  inline void seed(uint64_t seed) { state = seed; }
  inline uint32_t next_int() {
    state += kAdd; __uint128_t tmp = (__uint128_t)state * kMul1;
    uint64_t m1 = (tmp >> 64) ^ tmp; tmp = (__uint128_t)m1 * kMul2;
    uint64_t m2 = (tmp >> 64) ^ tmp; return (uint32_t)m2;
  }
  inline uint32_t next_int(uint32_t max) { return next_int()%max; }
  inline uint32_t next_int(uint32_t min, uint32_t max) { return min + (next_int()%(max-min)); }
  inline double next_float() { return next_int(kMax) * kInvMax; }
} rng;
 
std::vector<long long> A;
std::vector<long long> B;
std::vector<long long> Best;
int N;
long long T;
 
long long BestScore, current;
 
void shuffle() {
  if (N > 1000) for (int i = 0; i < N; i++) {
    rng.seed(142857);
    std::swap(A[i], A[rng.next_int(i, N)]);
  }
  for (int i = 0; i < N; i++) {
    std::swap(B[i], B[rng.next_int(i, N)]);
  }
}
 
void RecursiveDec(long long T) {
  std::vector<long long> sols;
  long long ss = 0;
  int lim = 500;
  while (B.size() > lim) {
    ss += A[B.size() - 1] * B.back();
    sols.push_back(B.back());
    B.pop_back();
  }
  std::sort(A.begin(), A.begin() + B.size());
  std::sort(B.begin(), B.end());
  int id = 0;
 
  std::vector<long long> Bs[1001];
  std::function<bool(const std::vector<long long>&, long long)> fct = [&](
      const std::vector<long long>& B, long long sum) {
    if (id++ % 100000 == 0 && get_time() > end_time) throw 42;
    long long min = 0;
    long long max = 0;
    int id = 0;
    for (long long v : B) {
      min += v * A[B.size() - id - 1];
      max += v * A[id];
      id++;
    }
    if (sum + min >= T) {
      long long sc = sum + min - T;
      if (sc < BestScore) {
        BestScore = sc;
        Best = sols;
        Best.insert(Best.end(), B.begin(), B.end());
        LOG_WARNING("new best: %lld", BestScore);
        if (BestScore == 0) throw 12;
      }
      return false;
    }
    if (sum + max <= T) {
      long long sc = T - sum - max;;
      if (sc < BestScore) {
        BestScore = sc;
        Best = sols;
        Best.insert(Best.end(), B.rbegin(), B.rend());
        LOG_WARNING("new best: %lld", BestScore);
        if (BestScore == 0) throw 12;
      }
      return true;
    }
    long long a = A[B.size()-1];
    auto& bs = Bs[B.size()];
    bs.insert(bs.end(), B.begin() + 1, B.end());
    sols.push_back(0);
    for (int i = 0;; i++) {
      long long v = B[i];
      sols.back() = v;
      long long nsum = sum + a * v;
      if (!fct(bs, nsum)) break;
      if (i == bs.size()) break;
      bs[i] = v;
    }
    bs.clear();
    sols.pop_back();
    return true;
  };
  try {
    fct(B, ss);
  } catch(int e) {}
  std::reverse(Best.begin(), Best.end());
}
 
int main() {
  scanf("%d %lld\n", &N, &T);
  BestScore = T;
  A.resize(N);
  B.resize(N);
  for (int i = 0; i < N; i++) scanf("%lld\n", &A[i]);
  for (int i = 0; i < N; i++) scanf("%lld\n", &B[i]);
  shuffle();
  for (int i = 0; i < N; i++) current += A[i] * B[i];
 
  RecursiveDec(T);// else Recursive(T);
  B = Best;
 
  current = 0;
  for (int i = 0; i < N; i++) current += A[i] * B[i];
  LOG_WARNING("Best: %lld (%lld) (%zd %zd)\n", BestScore, std::abs(current - T), A.size(), B.size());
 
#ifndef LOCAL
  for (int i = 0; i < N; i++) printf("%lld ", A[i]);
  printf("\n");
  for (int i = 0; i < N; i++) printf("%lld ", B[i]);
#endif
  return 0;
}