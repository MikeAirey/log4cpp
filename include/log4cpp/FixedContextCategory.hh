/*
 * FixedContextCategory.hh
 *
 * Copyright 2001, LifeLine Networks BV (www.lifeline.nl). All rights reserved.
 * Copyright 2001, Bastiaan Bakker. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#ifndef _LOG4CPP_FIXEDCONTEXTCATEGORY_HH
#define _LOG4CPP_FIXEDCONTEXTCATEGORY_HH

#include "log4cpp/Export.hh"
#include "log4cpp/Category.hh"

namespace log4cpp {

    /**
     * This Category subclass replaces the NDC field in LoggingEvents with
     * a fixed context string. All handling of Appenders, etc. is delgated
     * to the 'normal' Category with the same name. Its intended use is 
     * for object instances that serve a single client: they contruct a 
     * FixedContextCategory with the client identifier as context. 
     * Unlike with regular Category instances one has to explicitly create
     * FixedContextCategory instances using the constructor. This also 
     * implies one has to take cake of destruction of the instance as well.
     * @since 0.2.4
     **/
    class LOG4CPP_EXPORT FixedContextCategory : public Category {

        public:

        /**
         * Constructor 
         * @param name the fully qualified name of this Categories delegate
         * Category.
         * @param context the context to fill the NDC field of LoggingEvents
         * with.
         * @param priority the priority for this Category. Defaults to
         * Priority::NOTSET
         **/
        FixedContextCategory(const std::string& name, 
                             const std::string& context = "");
        
        
        /**
         * Destructor for Category.
         **/
        virtual ~FixedContextCategory();
        
        /**
         * Set the context string used as NDC.
         * @param context the context string
         **/
        virtual void setContext(const std::string& context);

        /**
         * Return the context string used as NDC.
         * @return the context string.
         **/
        virtual std::string getContext() const;

        /**
         * Returns the assigned Priority, if any, for this Category.
         * @return Priority - the assigned Priority, can be Priority::NOTSET
         **/
        virtual Priority::Value getPriority() const throw();

        /**
         * Starting from this Category, search the category hierarchy for a
         * set priority and return it. Otherwise, return the priority 
         *  of the root category.
         * 
         * <p>The Category class is designed so that this method executes as
         * quickly as possible.
         **/
        virtual Priority::Value getChainedPriority() const throw();
        
        /**
         * Sets an Appender for this Category.
         * This method passes ownership from the caller to the Category.
         * @param appender The Appender this category has to log to.
         **/
        virtual void setAppender(Appender* appender);

        /**
         * Sets an Appender for this Category.
         * This method does not pass ownership from the caller to the Category.
         * @param appender The Appender this category has to log to.
         **/
        virtual void setAppender(Appender& appender);

        /**
         * Returns the Appender for this Category, or NULL if no Appender has
         * been set.
         * @returns The Appender.
         **/
        virtual Appender* getAppender() const;

        /**
         * Removes all appenders set for this Category. Currently a Category
         * can have only one appender, but this may change in the future.
         **/
        virtual void removeAllAppenders();

        /**
         * Returns true if the Category owns the Appender. In that case the
         * Category destructor will delete the Appender.
         **/
        virtual bool ownsAppender() const throw();

        /**
         * Call the appenders in the hierarchy starting at
         *  <code>this</code>.  If no appenders could be found, emit a
         * warning.
         * 
         * <p>This method always calls all the appenders inherited form the
         * hierracy circumventing any evaluation of whether to log or not to
         * log the particular log request.
         * 
         * @param LoggingEvent the event to log.
         **/
        virtual void callAppenders(const LoggingEvent& event) throw();
        
        /**
         * Set the additivity flag for this Category instance.
         **/
        virtual void setAdditivity(bool additivity);

        /**
         * Returns the additivity flag for this Category instance.
         **/        
        virtual bool getAdditivity() const throw();

       protected:

         /** 
         * Unconditionally log a message with the specified priority.
         * @param priority The priority of this log message.
         * @param message string to write in the log file
         **/  
        virtual void _logUnconditionally2(Priority::Value priority, 
                                          const std::string& message) throw();

        private:

        /**
         * The delegate category of this FixedContextCategory. 
         **/
        Category& _delegate;

        /** The context of this FixedContextCategory. */
         std::string _context;

    };

}
#endif // _LOG4CPP_FIXEDCONTEXTCATEGORY_HH
