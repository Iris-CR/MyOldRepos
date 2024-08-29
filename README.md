# MyOldRepos
&emsp;This is a place to put my old repos... durr
<br><br><br>
You can do the same using Git Bash, I did it using git subtrees, heres how you do it:<br>
First you clone the repository that you will store the old ones, with:<br>
<br>
&emsp;<em>git clone h<span>ttps://github.com/username/parent-repo.git</em><br>
&emsp;<em>cd parent-repo</em><br>
  <br>
Then you can add each old repo using:<br>
<br>
&emsp;<em>git subtree add --prefix=subdirectory-name h<span>ttps://github.com/username/repo-to-move.git main</em><br>
  <br>
Finally, just push to the Changes to GitHub:<br>
<br>
&emsp;<em>git push origin main</em>
