-- MySQL dump 10.13  Distrib 5.7.27, for Linux (x86_64)
--
-- Host: localhost    Database: aces
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
-- Table structure for table `event_definition_table`
--

DROP TABLE IF EXISTS `event_definition_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `event_definition_table` (
  `idevent_definition_table` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `event_discription` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idevent_definition_table`)
) ENGINE=InnoDB AUTO_INCREMENT=913 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `event_definition_table`
--

LOCK TABLES `event_definition_table` WRITE;
/*!40000 ALTER TABLE `event_definition_table` DISABLE KEYS */;
INSERT INTO `event_definition_table` VALUES (1,'System booted'),(2,'user logged in'),(3,'user logged out'),(4,'unlocked lock 1'),(5,'unlocked lock 2'),(6,'unlocked lock 3'),(7,'unlocked lock 4'),(8,'unlocked lock 5'),(9,'unlocked lock 6'),(10,'opened door 1'),(11,'opened door 2'),(12,'opened door 3'),(13,'opened door 4'),(14,'opened door 5'),(15,'opened door 6'),(16,'clicked uesers  button'),(17,'clicked access group button'),(18,'clicked access item button'),(19,'clicked system button'),(20,'clicked logs button'),(21,'clicked add user button'),(22,'clicked edit user button'),(23,'clicked delete user button'),(24,'clicked cancel button'),(25,'clicked save user button'),(26,'clicked exit button'),(27,'clicked add access item'),(28,'clicked edit access item'),(29,'clicked delete access item'),(30,'clicked save access item'),(31,'clicked add new access group'),(32,'clicked edit access group'),(33,'clicked delete access group'),(34,'clicked save access group'),(35,'Invalid Login attemped'),(36,'User Changed PIN code'),(37,'set time'),(911,'Door Forced Open ALARM');
/*!40000 ALTER TABLE `event_definition_table` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-10-15 16:03:04
