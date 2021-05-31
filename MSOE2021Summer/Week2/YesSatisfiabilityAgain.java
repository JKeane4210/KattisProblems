package keanej;

import java.util.Scanner;

public class YesSatisfiabilityAgain {
	public static boolean eval(int curr, int mask1, int mask2) {
		if (mask1 == 0) return true;
		return ((curr & mask1) ^ mask2) != 0;
	}
	
	public static void solve(Scanner in) {
		String[] nm = in.nextLine().split(" ");
		int n = Integer.parseInt(nm[0]), m = Integer.parseInt(nm[1]);
		int[][] ops = new int[m][2]; // need a second item to block off unused
		for (int i = 0; i < m; ++i) {
			String[] line = in.nextLine().split(" v ");
			int[] counts = new int[2*n]; // first half regs, second half nots
//			System.out.println(Arrays.toString(line));
			for (String piece: line) {
				int val;
				if (piece.charAt(0) == '~') {
					val = Integer.parseInt(piece.substring(2));
					++counts[val - 1 + n];
					if ((counts[val - 1] > 0 && (ops[i][0] & (1 << (val - 1))) == 0) ||
							(counts[val - 1 + n] > 0 && counts[val - 1] > 0)) {
						ops[i][0] &= ~(1 << (val - 1));
						ops[i][1] = 0;
						break;
					} else {
						ops[i][0] |= (1 << (val - 1)); // negations
					}
				} else {
					val = Integer.parseInt(piece.substring(1));
					++counts[val - 1];
					if ((counts[val - 1 + n] > 0 && (ops[i][0] & (1 << (val - 1))) != 0) || 
							(counts[val - 1 + n] > 0 && counts[val - 1] > 0)) {
						ops[i][0] &= ~(1 << (val - 1));
						ops[i][1] = 0;
						break;
					}
				}
				ops[i][1] |= (1 << (val - 1)); // used
			}
//			System.out.print(ops[i][0] + " ");
//			System.out.println(ops[i][1]);
		}
		for (int i = 0; i < 1 << n; ++i) {
			boolean satisfiable = true;
			for (int[] mask: ops) {
				if (!eval(i, mask[1], mask[0])) {
					satisfiable = false;
					break;
				}
			}
			if (satisfiable) {
//				System.out.println(i);
				System.out.println("satisfiable");
				return;
			}
		}
		System.out.println("unsatisfiable");
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int i = 0; i < cases; ++i) {
			solve(in);
		}
	}
}
