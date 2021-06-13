package keanej;

import java.util.Scanner;
import java.util.ArrayList;

public class StackingCups {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		ArrayList<Pair<String>> arr = new ArrayList<>();
		int cups = in.nextInt();
		for (int i = 0; i < cups; ++i) {
			if (in.hasNextInt()) { // diameter
				int r = in.nextInt();
				arr.add(new Pair<String>(r, in.next()));
			} else {
				String s = in.next();
				arr.add(new Pair<String>(in.nextInt() * 2, s));
			}
		}
		arr.sort((a, b)-> {if (a.first < b.first) {
				return -1;
			} else if (a.first == b.first) {
				return 0;
			} else {
				return 1;
			}});
		for (Pair<String> s: arr) {
			System.out.println(s.second);
		}
	}
	
	private static class Pair<F> {
		public Integer first;
		public F second;
		public Pair(Integer first, F second) {
			this.first = first;
			this.second = second;
		}
	}
	
 }
