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
-- Table structure for table `locks`
--

DROP TABLE IF EXISTS `locks`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `locks` (
  `lockname` char(10) COLLATE utf8_bin NOT NULL,
  `sun_lock` char(5) COLLATE utf8_bin NOT NULL,
  `sun_unlock` char(5) COLLATE utf8_bin NOT NULL,
  `mon_lock` char(5) COLLATE utf8_bin NOT NULL,
  `mon_unlock` char(5) COLLATE utf8_bin NOT NULL,
  `tue_lock` char(5) COLLATE utf8_bin NOT NULL,
  `tue_unlock` char(5) COLLATE utf8_bin NOT NULL,
  `wed_lock` char(5) COLLATE utf8_bin NOT NULL,
  `wed_unlock` char(5) COLLATE utf8_bin NOT NULL,
  `thu_lock` char(5) COLLATE utf8_bin NOT NULL,
  `thu_unlock` char(5) COLLATE utf8_bin NOT NULL,
  `fri_lock` char(5) COLLATE utf8_bin NOT NULL,
  `fri_unlock` char(5) COLLATE utf8_bin NOT NULL,
  `sat_lock` char(5) COLLATE utf8_bin NOT NULL,
  `sat_unlock` char(5) COLLATE utf8_bin NOT NULL,
  `enabled` int(1) DEFAULT '0',
  `sun_enable` int(1) DEFAULT '1',
  `mon_enable` int(1) DEFAULT '1',
  `tue_enable` int(1) DEFAULT '1',
  `wed_enable` int(1) DEFAULT '1',
  `thu_enable` int(1) DEFAULT '1',
  `fri_enable` int(1) DEFAULT '1',
  `sat_enable` int(1) DEFAULT '1',
  `alldayssame` int(1) DEFAULT '0',
  `id` int(5) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='locks';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `locks`
--

LOCK TABLES `locks` WRITE;
/*!40000 ALTER TABLE `locks` DISABLE KEYS */;
INSERT INTO `locks` VALUES ('outterdoor','10:20','01:10','00:00','01:15','00:00','01:15','00:00','01:15','00:00','01:45','00:00','01:15','00:00','01:15',1,1,1,1,1,1,1,1,0,1),('innerdoor','00:00','01:10','00:00','01:10','00:00','01:15','00:00','01:20','00:00','01:45','00:00','01:15','00:00','01:15',0,1,1,1,1,1,1,1,0,2),('shutter','10:20','01:10','00:00','01:10','00:00','01:30','00:00','01:20','00:00','01:45','00:00','01:15','00:00','01:15',0,1,1,1,1,1,1,1,0,3),('sidecar','00:00','01:10','00:00','01:10','00:00','01:30','00:00','01:20','00:00','01:45','00:00','01:15','00:00','01:15',0,1,1,1,1,1,1,1,0,4),('base','10:20','01:10','00:00','01:10','00:00','01:30','00:00','01:20','00:00','01:01','00:00','01:15','00:00','01:15',0,1,1,1,1,1,1,1,0,5);
/*!40000 ALTER TABLE `locks` ENABLE KEYS */;
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
