# MyOldRepos
This is a place to put my old repos... durr  
You can do the same using Git Bash, I did it using git subtrees, heres how you do it:<br>
First you clone the repository that you will store the old ones, with:  
``` git
git clone h<span>ttps://github.com/username/parent-repo.git
cd parent-repo
```  
Then you can add each old repo using:  
``` git
git subtree add --prefix=subdirectory-name h<span>ttps://github.com/username/repo-to-move.git main
```  
Finally, just push to the Changes to GitHub:  
``` git
git push origin main
```
