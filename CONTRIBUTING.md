# Note
- Do not open multiple pull request all at once.
- There are also times where you will be asked to fixed a certain part of code in your pull request, at this point you don't need to close your current pull request and create a new one, you just need to ```git push``` the fixes to your forked repository and that change will already appear in the pull request.
- Your pull request might not be accepted or accepted right away if there is something wrong with it, but no matter what the reason is please be respectful.

# Opening Issues and Pull Requests
- Explain well the issue you open and use an appropriate **issue label**, make sure that you follow the **CODE_OF_CONDUCT.md**.
- When opening a pull request, say for example you have implemented a function or method. You should check if there is already an existing test program for that function or method inside the ```tests\``` folder, if there is none you should make one for it, follow the format of the other previous test programs and add the new test programs only in the makefile's ```test:``` section.

# How To Contribute?

1. Follow the **CODE_OF_CONDUCT.md** this is applicable in issues, pull requests, issue and pull request comments, source code comments and any other medium of communication that is related to this repository, always be nice and respectful.
2. Fork this repository in your **GitHub account**.
3. Using **git**, clone the forked repository to your local device (PC/Laptop/etc.) using ```git clone https://github.com/username/APA.git``` command.
4. Apply your changes to the source code then add and commit it using ```git add .``` and ```git commit -m "commit message"```.
5. Push the local (on device) clone repository in your forked GitHub repository (forked github repository online) using ```git push``` command.
6. Open a pull request from your forked repository to this repository.
7. Add a summary explanation comment to your pull request and link the issue it solves or implements if there is one.
