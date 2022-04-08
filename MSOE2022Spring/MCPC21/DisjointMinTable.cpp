////
//// Created by Jonny Keane on 3/21/22.
////
//
//#include <bits/stdc++.h>
//
//class DisjointMintTable {
//public:
//    int n;
//    int levels;
//    int * nums;
//    int * table;
//
//    DisjointMintTable(vector<int> v, int n, int levels) : n(n), levels(levels)  {
//        nums = new int[n];
//        for (int idx = 0; idx < n; ++idx) {
//            if (idx < v.size()) {
//                input
//            }
//        }
//        table = (int *)malloc(n * levels * sizeof(int));
//        memset(table, 0, n * levels * sizeof(int));
//        for (int level = 0; level < levels; ++level) {
//            for (int block = 0; block < (1 << levels); ++block) {
//                int start = block << (levels - level);
//                int end = (block + 1) << (levels - level);
//                int mid = (start + end) >> 1;
//                table[level][mid] = nums[]
//            }
//        }
//    }
//
//
//};