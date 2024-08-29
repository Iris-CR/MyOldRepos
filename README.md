# MyOldRepos
This is a place to put my old repos... durr
<br><br><br>
You can do the same using Git Bash, I did it using git subtrees, heres how you do it:<br>
First you clone the repository that you will store the old ones, with:<br>
<br>
&emsp;git clone https://github.com/username/parent-repo.git<br>
&emsp;cd parent-repo<br>
  <br>
Then you can add each old repo using:<br>
&emsp;git subtree add --prefix=subdirectory-name https://github.com/username/repo-to-move.git main<br>
  <br>
Finally, just push to the Changes to GitHub:<br>
<br>
&emsp;git push origin main
