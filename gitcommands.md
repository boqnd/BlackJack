# GitBash and CommandLine

GitBash and CommandLine helpful commands.

&nbsp;

## NORMAL WORKFLOW 

First navigate to the project folder then execute this sequence of commands.


```console
  1) git pull
  2) git checkout develop
  3) git fetch --prune
  4) git checkout -b <name corresponding to the task you are going to working on>
  5) ... write code ...
  6) git add .
  7) git commit -m "<message corresponding to the change you have made>"
  8) git push
  9) git checkout develop
```
>*!(you should ***'git add .'*** and ***'git commit'*** after every small change)!*

&nbsp;

## Command line commands
Commands to use in the bash shell.

```console
  cd <directory name> -> change directory
  cd ..   - - - - - - -> go one directory backwards
  cd    - - - - - - - -> change directory to root
  ls    - - - - - - - -> list
  pwd   - - - - - - - -> prints current directory path
  clear   - - - - - - -> clear terminal
```

&nbsp;

## GIT COMMANDS
Commands to use in git bash.

```console
  git clone <url>   - - - - - - -> cloning git repository locally

  git pull    - - - - - - - - - -> download newest version of the code from GitHub
  git push    - - - - - - - - - -> upload your changes of the code to GitHub

  git add .   - - - - - - - - - -> prepare all files to be uploaded
  git commit -m " message "   - ->  final step before uploading the files 
                                      (must write a comment of what you've changed)

  git branch -a   - - - - - - - -> show all branches and remotes stored locally
  git branch <branch name>  - - -> create branch
  git checkout <branch name>  - -> change branch
  git checkout -b <branch name> -> create branch and checkout to it
  git fetch --prune   - - - - - -> update the locally stored branches and remotes,
                                     and delete the not existing on GitHub branches and remotes
```
