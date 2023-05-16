# Домашнее задание к занятию «Работа с PostgreSQL из C++»


### CentOS/RHEL/Fedora DEPS:
```
sudo yum install postgresql-devel
```

### Debian/Ubuntu DEPS:
```
sudo apt-get install libpq-dev
```

### BUILD
```
git clone git@github.com:Spybull/netology.git
cd netology/cpp-sql/05
git submodule update --init --recursive
cmake .
cmake --build .
```

### CHECK
```
docker-compose up -d
```
