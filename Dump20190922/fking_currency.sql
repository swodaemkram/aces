-- MySQL dump 10.13  Distrib 5.7.27, for Linux (x86_64)
--
-- Host: localhost    Database: fking
-- ------------------------------------------------------
-- Server version	5.7.27-0ubuntu0.18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `currency`
--

DROP TABLE IF EXISTS `currency`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `currency` (
  `country_code` varchar(5) COLLATE utf8_bin NOT NULL,
  `type` varchar(5) COLLATE utf8_bin NOT NULL,
  `value` int(4) NOT NULL,
  `symbol` varchar(10) COLLATE utf8_bin NOT NULL,
  `id` int(5) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=48 DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='locks';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `currency`
--

LOCK TABLES `currency` WRITE;
/*!40000 ALTER TABLE `currency` DISABLE KEYS */;
INSERT INTO `currency` VALUES ('USD','NOTE',100,'$',1),('USD','NOTE',500,'$',2),('USD','NOTE',1000,'$',3),('USD','NOTE',2000,'$',4),('USD','NOTE',5000,'$',5),('USD','NOTE',10000,'$',6),('USD','COIN',1,'c',7),('USD','COIN',5,'c',8),('USD','COIN',10,'c',9),('USD','COIN',25,'c',10),('EURO','NOTE',500,'€',11),('EURO','NOTE',1000,'€',12),('EURO','NOTE',2000,'€',13),('EURO','NOTE',5000,'€',14),('EURO','NOTE',10000,'€',15),('EURO','NOTE',20000,'€',16),('EURO','NOTE',50000,'€',17),('EURO','COIN',1,'c',18),('EURO','COIN',2,'c',19),('EURO','COIN',5,'c',20),('EURO','COIN',10,'c',21),('EURO','COIN',20,'c',22),('EURO','COIN',50,'c',23),('EURO','COIN',100,'€',24),('EURO','COIN',200,'€',25),('PESO','NOTE',2000,'$',26),('PESO','NOTE',5000,'$',27),('PESO','NOTE',10000,'$',28),('PESO','NOTE',20000,'$',29),('PESO','NOTE',50000,'$',30),('PESO','COIN',100,'$',31),('PESO','COIN',200,'$',32),('PESO','COIN',500,'$',33),('PESO','COIN',1000,'$',34),('PESO','COIN',2000,'$',35),('PESO','COIN',20,'¢',36),('PESO','NOTE',50,'¢',37),('ILS','NOTE',2000,'₪ ',38),('ILS','NOTE',5000,'₪',39),('ILS','NOTE',10000,'₪',40),('ILS','NOTE',20000,'₪',41),('ILS','COIN',100,'₪',42),('ILS','COIN',200,'₪',43),('ILS','COIN',500,'₪',44),('ILS','COIN',1000,'₪',45),('ILS','COIN',10,'agorot',46),('ILS','COIN',50,'agorot',47);
/*!40000 ALTER TABLE `currency` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-09-22 20:40:28
