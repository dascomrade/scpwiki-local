



--regular searchterms

CREATE TABLE mediumSearch (
  id INT PRIMARY KEY,
term VARCHAR(4096),
objects VARCHAR(4096)
);

--Classes

CREATE TABLE `types` (
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
critical VARCHAR(4096),
joke BOOLEAN
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
