/**
 * Climbing Stairs
 * You are climbing a stair case.
 * It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 *
 * Hint: Dynamic Programming
 */

 class ClimbingStairs {
 public:
 	int climbStairs(int n) {
 		int f1 = 1;
 		int f2 = 2;
 		int fn;

 		if (n == 1) return f1;
 		if (n == 2) return f2;

 		for (int i=3; i<=n; i++) {
 			fn = f1 + f2;
 			f1 = f2;
 			f2 = fn;
 		}

 		return fn;
 	}
 }