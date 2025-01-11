from typing import List

class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique_emails: set[str] = set()
        for email in emails:
           local_name, domain_name = email.split('@')
           local_name = local_name.split('+')[0]
           local_name = local_name.replace('.', '')
           email = local_name + '@' + domain_name
           unique_emails.add(email)
        return len(unique_emails)


def main():
    # Sample test cases
    emails1 = ["test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"]
    emails2 = ["a@leetcode.com", "b@leetcode.com", "c@leetcode.com"]

    solution = Solution()

    # Test case 1
    result1 = solution.numUniqueEmails(emails1)
    print(f"Number of unique emails (Test case 1): {result1}")  # Expected output: 2

    # Test case 2
    result2 = solution.numUniqueEmails(emails2)
    print(f"Number of unique emails (Test case 2): {result2}")  # Expected output: 3


if __name__ == "__main__":
    main()