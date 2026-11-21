--regular searchterms

CREATE TABLE mediumSearch (
  id INT PRIMARY KEY,
antimeme VARCHAR(4096),
memetic VARCHAR(4096),
`blob` VARCHAR(4096),
teddy VARCHAR(4096),
animal VARCHAR(4096),
machine VARCHAR(4096),
item VARCHAR(4096),
food VARCHAR(4096),
humanoid VARCHAR(4096),
friendly VARCHAR(4096),
hostile VARCHAR(4096),
neutral VARCHAR(4096),
sapient VARCHAR(4096),
statue VARCHAR(4096),
mask VARCHAR(4096)
);

--Classes

CREATE TABLE classes (
  id INT PRIMARY KEY,
keter VARCHAR(4096),
euclid VARCHAR(4096),
safe VARCHAR(4096),
thaumiel VARCHAR(4096),
neutral VARCHAR(4096),
dark VARCHAR(4096),
vlam VARCHAR(4096),
keneq VARCHAR(4096),
ekhi VARCHAR(4096),
amida VARCHAR(4096),
notice VARCHAR(4096),
caution VARCHAR(4096),
warning VARCHAR(4096),
danger VARCHAR(4096),
critical VARCHAR(4096)
);

--release data

CREATE TABLE series (
  id INT PRIMARY KEY,
  SeriesI INT,
  SeriesII INT,
  SeriesIII INT,
  SeriesIV INT,
  SeriesV INT,
  SeriesVI INT,
  SeriesVII INT,
  SeriesVIII INT,
  SeriesIX INT,
  SeriesX INT,
  SeriesXI INT
);
