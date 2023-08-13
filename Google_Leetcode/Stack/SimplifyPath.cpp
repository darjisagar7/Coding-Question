class Solution:
    def simplifyPath(self, path: str) -> str:
        components = path.split("/")

        stack = []

        for directory in components:
            if directory == "." or not directory:
                continue;
            elif directory == "..":
                if stack:
                    stack.pop()
            else:
                stack.append(directory)


        return "/" + "/".join(stack)
