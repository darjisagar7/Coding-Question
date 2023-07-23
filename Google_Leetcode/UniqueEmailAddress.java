class Solution {
    public int numUniqueEmails(String[] emails) {

      Set<String> validEmails = new HashSet<String>();
      
      for (String email : emails) {
        final String[] splitedEmail = email.split("@");
        if (splitedEmail.length == 2) {
          validEmails.add(getTruncatedString(splitedEmail));
        }
      }
      
      return validEmails.size();
    }

    String getTruncatedString(final String[] splitedEmail) {
      String ans;
      ans = splitedEmail[0].split("\\+")[0].replace(".", "");
      System.out.println(ans + splitedEmail[1]);
      return ans + "@" + splitedEmail[1];
    }
}
