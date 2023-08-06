import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static Long n, m;

    public static void solve() {
        long ans = 0L;
        if (n == 1) {
            ans = m * 8;
        } else if (n == 5) {
            ans = m * 8 + 4;
        } else {
            ans = (m + 1) / 2 * 8 + ((m % 2 == 1) ? (1 - n) : (n - 1));
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Long.parseLong(br.readLine());
        m = Long.parseLong(br.readLine());

        solve();
    }
}
