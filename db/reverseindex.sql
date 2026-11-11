CREATE DATABASE article_index;
CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

CREATE TABLE articles (
    id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
    nickname VARCHAR(64),
    series INT NOT NULL
);

CREATE TABLE keywords(
    id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
    word VARCHAR(45) NOT NULL,
    articlesForWord BIGINT
);

CREATE TABLE article_keywords(
    id BIGSERIAL PRIMARY KEY,
    keyword_id UUID NOT NULL REFERENCES keywords(id),
    article_id UUID NOT NULL REFERENCES articles(id)
);


CREATE INDEX idx_keywords_name ON keywords(word);
CRATE INDEX article_keyword_id ON article_keywords(keyword_id);
