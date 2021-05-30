package keanej;

import java.util.Scanner;

public class Eligbility {
	public static int parseYear(String date) {
		return Integer.parseInt(date.split("/")[0]);
	}
	
	public static void solve(String name, String postSec, String birth, int courses) {
		int postSecYear = parseYear(postSec);
		int birthYear = parseYear(birth);
		if (postSecYear >= 2010 || birthYear >= 1991) {
			System.out.println(name + " eligible");
		} else if (courses > 40) {
			System.out.println(name + " ineligible");
		} else {
			System.out.println(name + " coach petitions");
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int i = 0; i < n; ++i) {
			String name = in.next();
			String postSec = in.next();
			String birth = in.next();
			int courses = in.nextInt();
			solve(name, postSec, birth, courses);
		}
	}
}
