#ARDITO_topics

Git Submodule for topic configuration

## How to use

- Add to your repository as a git submodule with the following commands 

list all current submodules
```bash
git config --file .gitmodules --name-only --get-regexp path
```

Add Submodule
```bash
git submodule add git@github.com:ilkimo/ARDITO_topics.git
```

changes take place in .gitmodules 

Checking out a particular branch of this submodule
```bash
cd ARDITO_topics
git checkout <branchname>
git pull
```

